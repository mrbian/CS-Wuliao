var Promise = require('bluebird');
var Sequelize = Promise.promisifyAll(require('sequelize'));
var sequelize = new Sequelize('wuliao','','',{
    dialect:'mysql',
    host:''
});

var db = {
wuliao_user : sequelize.define('wuliao_user',{
   user_account:{
       type:Sequelize.INTEGER,
       allowNull:false,
		unique:true,
		allowNull:false
	},
   user_password:{
       type:Sequelize.TEXT,
       allowNull:false
   },
   user_name:{
       type:Sequelize.TEXT,
       allowNull:false
   },
   user_friend:{
       type:Sequelize.TEXT,
       allowNull:true,
	   defaultValue:null
   },
   user_own_group:{
	   type:Sequelize.INTEGER,
	   allowNull:true,
	   defaultValue:null
   },
	user_join_group:{
	   type:Sequelize.TEXT,
	   allowNull:true,
	   defaultValue:null
	},
	user_email:{
		type:Sequelize.TEXT,
		allowNull:false
	},
	user_grant:{
		type:Sequelize.INTEGER,
		allowNull:false,
		defaultValue:1
	},
	id:{
		type:Sequelize.INTEGER,
		autoIncrement:true,
		primaryKey:true
	}
},{
    timestamps: false
}),

wuliao_group : sequelize.define('wuliao_group',{
    group_name:{
        type:Sequelize.TEXT,
		allowNull:false
    },
    group_account:{
        type:Sequelize.INTEGER,
		unique:true,
		allowNull:false
    },
    group_content:{
        type:Sequelize.TEXT,
		allowNull:false
    },
    group_describe:{
        type:Sequelize.TEXT,
        allowNull:false
    },
    id:{
        type:Sequelize.INTEGER,
        primaryKey:true,
        autoIncrement:true
    }
},{
    timestamps:false
}),

sequelize:sequelize
};

db.wuliao_user.sync({force:false});
db.wuliao_group.sync({force:false});

module.exports = db;
