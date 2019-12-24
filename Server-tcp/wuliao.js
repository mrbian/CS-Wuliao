var Promise = require('bluebird');
var Sequelize = require('sequelize');
var net = Promise.promisifyAll(require('net'));
var server = net.createServer();
var db = require('./db.js');
var sockets_reg = [];
var sockets_user = [];
server.on('connection',function(socket){
    console.log('new connection');
    socket.on('data',function(_data){
       var data = _data.toString().split('-');
       switch(data[0]){

           //0
           case "add_user":
               (function(){
               db.wuliao_user.findOne({where:["user_account = ?",data[3]],attributes:["user_account"]}).then(function(account){
               if (!account) {
                   db.sequelize.query('insert into wuliao_users (user_name,user_password,user_account,user_email) values (:name,:password,:account,:email)', {replacements: {
                       name: data[1], password: data[2], account: data[3], email: data[4]
                   }}).then(function(){
                       socket.write("add_user-success");
                   }).catch(function (err) {
                       console.log(err);
                   });
               }else{
                    socket.write("add_user-fail");
               }
           });
               }());
           break;

           //1
           case "set_user_name":
               (function(){
               var num = parseInt(data[1]);
               db.wuliao_user.update({
                   user_name:data[2]
               },{
                   where:{
                       user_account:{
                           $eq:num
                       }
                   }
               }).then(function(result){
                   if(result[0] === 1){
                       socket.write("set_name-success");
                   }else{
                       socket.write("set_name-fail")
                   }
               }).catch(function(err){
                    console.log(err);
               });
               }());
           break;


           //2
           case "set_user_password":
               (function(){
                   var num= parseInt(data[1]);
                   db.wuliao_user.update({
                       user_password:data[2]
                   },{
                       where:{
                           user_account:{
                               $eq:num
                           }
                       }
                   }).then(function(result){
                       if(result[0] === 1){
                           socket.write("set_password-success");
                       }else{
                           socket.write("set_password-fail")
                       }
                   }).catch(function(err){
                       console.log(err);
                   });
               }());
               break;


           //3
           case "user_login":
               (function(){
                   var num = parseInt(data[1]);
                   db.wuliao_user.findOne({where:{user_account:num,user_password:data[2]},attributes:["user_account","user_password","user_name","user_friend","user_own_group","user_join_group","user_email","user_grant"]})
                       .then(function(user){
                           if(!user){
                               socket.write("user_login|fail"+"|wrong");
                           }else{
                               var i;
                               for(i=0;i<sockets_reg.length;i++){
                                   if(sockets_reg[i].name == user.dataValues.user_account){
                                       throw "already_login";
                                   }
                               }
                               socket.name = user.dataValues.user_account;
                               sockets_reg.push(socket);
                               socket.write("user_login|success|"+user.dataValues.user_account+"|"+user.dataValues.user_password
                                   +"|"+user.dataValues.user_name+"|"+user.dataValues.user_friend+"|"+user.dataValues.user_own_group+"|"+user.dataValues.user_join_group+
                                   "|"+user.dataValues.user_email+"|"+user.dataValues.user_grant);
                           }
                       }).catch(function(error){
                           socket.write("user_login|fail|"+error);
                       });
               }());
               break;


           //4
           case "find_friend":
               (function(){
                   var num = parseInt(data[1]);
                   db.wuliao_user.findOne({where:{user_account:num},attributes:["user_name","user_account"]})
                       .then(function(results){
                           if(results) {
                               var res = "find_friend-success-" + results.dataValues.user_name +'-'+results.dataValues.user_account;
                               socket.write(res);
                           }else{
                               socket.write("find_friend-fail");
                           }
                       });
               }());
               break;


           //5
           case "add_friend":
               (function(){
                   var account = parseInt(data[1]);
                   var friend_account = parseInt(data[2]);
                   var friend_data;
                   try {
                       if (account === friend_account) {
                           throw "only_one";
                       }
                       db.wuliao_user.findOne({where: {user_account: friend_account}, attributes: ["user_account","user_grant"]})
                           .then(function (results) {
                               if (!results) {
                                   var str = "no_such_user";
                                   throw  str;
                               }else if(results.dataValues.user_grant == 2){
                                   throw "need_check";
                               }else if(results.dataValues.user_grant == 3){
                                   throw "no_add";
                               }
                           }).then(function () {
                               db.wuliao_user.findOne({where: {user_account: account}, attributes: ["user_friend"]})
                                   .then(function (results) {
                                       friend_data = results.dataValues.user_friend;
                                       if (friend_data) {             //当不为null的时候
                                           friend_data = friend_data.split('-');
                                           if (friend_data.indexOf(data[2]) === -1) {  //不存在此好友的时候，添加此好友,当已经存在此好友的时候，throw错误
                                               friend_data.push(data[2]);
                                               friend_data = friend_data.join('-');
                                           } else {
                                               var str = "already_have";
                                               throw str;
                                           }
                                       } else {
                                           friend_data = data[2];
                                       }
                                   }).then(function () {
                                       db.wuliao_user.update({
                                           user_friend: friend_data
                                       }, {
                                           where: {
                                               user_account: {
                                                   $eq: account
                                               }
                                           }
                                       }).then(function(result){
                                           if(result == 1){
                                               socket.write("add_friend-add_success-"+data[2]);
                                           }else{
                                               socket.write("add_friend-add_fail");
                                           }
                                       });
                                       db.wuliao_user.findOne({
                                           where:{
                                               user_account:friend_account
                                           },
                                           attributes:["user_friend"]
                                       }).then(function(result){
                                           if(!result.dataValues.user_friend){
                                               var acc = account.toString();
                                           }else{
                                               var acc = result.dataValues.user_friend.split('-');
                                               acc.push(account.toString());
                                               acc = acc.join('-');
                                           }
                                           db.wuliao_user.update({
                                               user_friend:acc
                                           },{
                                               where:{
                                                   user_account:{
                                                       $eq:friend_account
                                                   }
                                               }
                                           }).then(function(){
                                               var i;
                                               for(i=0;i<sockets_user.length;i++){
                                                   console.log(sockets_user[i].name);
                                                   if(sockets_user[i].name == friend_account){
                                                       sockets_user[i].write("add_friend-add_success-"+data[1]);
                                                   }
                                               }
                                           });
                                       })
                                   }).catch(function (err) {
                                       socket.write("add_friend-" + err);
                                   });
                           }).catch(function (err) {
                               socket.write("add_friend-" + err);
                           });
                   }catch(err){
                       socket.write("add_friend-"+err);
                   }
               }());
               break;


           //6
           case "set_grant":
               (function () {
                   var account = parseInt(data[1]);
                   var grant = parseInt(data[2]);
                   db.wuliao_user.update({
                       user_grant:grant
                   },{
                       where:{
                           user_account:{
                               $eq:account
                           }
                       }
                   }).then(function(result){
                       if(result[0] === 1){
                           socket.write("set_grant-success");
                       }else {
                           socket.write("set_grant-fail");
                       }
                   });
           }());
               break;

           //7
           case "create_group":
               (function(){
                   var account = parseInt(data[1]);
                   var group_account = parseInt(data[2]);
                   var group;
                       db.wuliao_user.findOne({
                           where:{
                               user_account:account
                           },
                           attributes:["user_own_group"]
                       }).then(function(result){
                           if(result.dataValues.user_own_group){                     //当已经有自己的
                               throw "already_own";
                           }else{
                               db.wuliao_user.findOne({    //select出join_group的值然后进行插入与update操作
                                   where:{
                                       user_account:account
                                   },
                                   attributes:["user_join_group"]
                               }).then(function(results){
                                   if(results.dataValues.user_join_group) {
                                       group = results.dataValues.user_join_group.split('-');
                                       if (group.indexOf(data[2]) === -1) {
                                           group.push(data[2]);
                                           group = group.join('-');
                                       } else {
                                           throw "already_have";
                                       }
                                   }else{
                                       group = data[2];
                                   }
                               }).then(function(){
                                   db.wuliao_user.update({
                                       user_own_group: group_account,
                                   },{
                                       where:{
                                           user_account:{
                                               $eq:account
                                           }
                                       }
                                   });
                               }).then(function(){
                                 db.sequelize.query("insert into wuliao_groups (group_name,group_account,group_content,group_describe) values (:name,:account,:content,:describe)",{
                                     replacements:{name:data[3],account:group_account,content:account,describe:data[4]}
                                 });
                               }).then(function(){
                                  db.wuliao_user.update({
                                          user_join_group: group
                                      },
                                      {
                                          where:{
                                          user_account:account
                                      }
                                  }).then(function(){
                                      socket.write("user_create_group-success-"+data[2]);
                                  });
                               }).catch(function(err){
                                   socket.write("user_create_group-fail-"+err);
                               });
                           }
                       }).catch(function(error){
                           socket.write("user_create_group-fail-"+error);
                       });
               }());
               break;


           //8
           case "find_group":
               (function(){
                   var group_account = parseInt(data[1]);
                   db.wuliao_group.findOne({
                       where:{
                           group_account:group_account
                       },
                       attributes:["group_account"]
                   }).then(function(result){
                       if(result){
                           socket.write("find_group-success-"+result.dataValues.group_account);
                       }else{
                           socket.write("find_group-fail-no_result");
                       }
                   });
               }());
               break;


           //9
           case "join_group":
               (function(){
                   var account = parseInt(data[1]);
                   var group_account = parseInt(data[2]);
                   var group;
                   db.wuliao_user.findOne({
                       where:{
                           user_account:account
                       },
                       attributes:["user_join_group"]
                   }).then(function(result){
                       if(result.dataValues.user_join_group) {
                            group = result.dataValues.user_join_group.split('-');
                           if(group.indexOf(data[2]) === -1){             //没有此群组
                                group.push(data[2]);
                               group = group.join('-');
                           }else{
                               throw "already_have";
                           }
                       }else{
                            group = data[2];
                       }
                   }).then(function(){
                       db.wuliao_user.update({
                          user_join_group:group
                       }, {
                           where: {
                               user_account: {
                                   $eq: account
                               }
                           }
                       });
                   }).then(function(){
                       socket.write("user_join_group-success-"+group_account);
                   }).catch(function(err){
                       socket.write("user_join_group-fail-"+err);
                   });
               }());
               break;
           //10
           case "inform":
               (function(){
                   socket.name = data[1];
                   sockets_user.push(socket);
               }());
               break;
           case "send_single_message":
               (function(){
                   var i,flag = 0;
                   for(i=0;i<sockets_user.length;i++){
                       if(sockets_user[i].name == data[2]){
                           sockets_user[i].write("send_single_message-success-"+data[1]+"-"+data[2]+"-"+data[3]);
                           flag = 1;
                       }
                   }
                   if(flag == 0){
                       socket.write("send_single_message-not_online"+data[1]+"-"+data[2]+"-"+data[3]);
                   }
               }());
               break;
           case "send_chat_message":
               (function(){
                   var i;
                   var account = data[1];
                   var message = data[2];
                   for(i=0;i<sockets_user.length;i++){
                       sockets_user[i].write("send_chat_message-"+account+"-"+message);
                   }
               }());
               break;
       }
    });

    setInterval(function(){
        var online_user,i;
        if(sockets_user.length !== 0) {
            online_user = sockets_user[0].name;
            for (i = 1; i < sockets_user.length; i++) {
                online_user = online_user + "-" + sockets_user[i].name;
            }
            for (i = 0; i < sockets_user.length; i++) {
                sockets_user[i].write("give_online_user|success|"+online_user);  //不同种类消息使用|来连接
            }
        }
    },10000);

    socket.on('close',function(){
       console.log("connection closed");
       var index_reg = sockets_reg.indexOf(socket);
       var index_user = sockets_user.indexOf(socket);
       if(index_reg !== -1)
       sockets_reg.splice(index_reg,1);
       if(index_user !== -1)
       sockets_user.splice(index_user,1);
    });
    socket.on('error',function(err){
        console.log(err);
    });
});

server.on('close',function(){
   console.log('server close');
});

server.on('error',function(err){
   console.log('Server error:',err.message);
});
server.listen(5000);