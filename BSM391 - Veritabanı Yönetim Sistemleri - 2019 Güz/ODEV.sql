CREATE SCHEMA "Post";


CREATE TABLE "Post"."Posts"(
	"PID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	"Description" Text,
	"PostByUID" Integer NOT NULL,
	"PostDate" DateTime NOT NULL,
	CONSTRAINT "lnk_Users_Posts" FOREIGN KEY ( "PostByUID" ) REFERENCES "Users"( "UID" )
);


CREATE TABLE "Post"."Questions"(
	"PID" Integer NOT NULL,
	"QID" Integer NOT NULL,
	"Title" Text,
PRIMARY KEY ( "PID", "QID" ),
	CONSTRAINT "lnk_Posts_Questions" FOREIGN KEY ( "PID" ) REFERENCES "Posts"( "PID" )
);


CREATE TABLE "Post"."Answers"(
	"PID" Integer NOT NULL,
	"AID" Integer NOT NULL,
	"QID" Integer NOT NULL,
	"IsSelected" Boolean,
PRIMARY KEY ( "PID", "AID" ),
	CONSTRAINT "lnk_Posts_Ans" FOREIGN KEY ( "PID" ) REFERENCES "Posts"( "PID" ),
	CONSTRAINT "lnk_Questions_Ans" FOREIGN KEY ( "QID" ) REFERENCES "Questions"( "QID" )
);


CREATE TABLE "Reputations"(
	"RepID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	"RepFrom" Integer NOT NULL,
	"PostID" Integer NOT NULL,
	"Value" Integer NOT NULL,
	CONSTRAINT "lnk_Users_Rep" FOREIGN KEY ( "RepFrom" ) REFERENCES "Users"( "UID" ),
	CONSTRAINT "lnk_Posts_Rep" FOREIGN KEY ( "PostID" ) REFERENCES "Posts"( "PID" )
);


CREATE TABLE "Pictures"(
	"PictureID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	"url" Text NOT NULL,
	"UploadedDate" DateTime NOT NULL,
	"UploadedBy" Integer NOT NULL,
	CONSTRAINT "lnk_Users_Pictures" FOREIGN KEY ( "UploadedBy" ) REFERENCES "Users"( "UID" )
);


CREATE TABLE "Tags"(
	"TID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	"TagName" Text NOT NULL,
	"TagDesc" Text );


CREATE TABLE "Privileges"(
	"PriID" Integer PRIMARY KEY AUTOINCREMENT,
	"PriName" Text NOT NULL,
	"PriDesc" Text,
	"Reputation" Integer NOT NULL );


CREATE TABLE "QuestionTags"(
	"QTID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	"TID" Integer NOT NULL,
	"QID" Integer NOT NULL ,
	CONSTRAINT "lnk_Tags_QTagsTID" FOREIGN KEY ( "TID" ) REFERENCES "Tags"( "TID" ),
	CONSTRAINT "lnk_Questions_QTagsQID" FOREIGN KEY ( "QID" ) REFERENCES "Questions"( "QID" )
);


CREATE TABLE "EmailVerification"(
	"EVID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	"UID" Integer NOT NULL,
	"Token" Text NOT NULL,
	"Valid" DateTime NOT NULL,
	"Date" DateTime NOT NULL,
	CONSTRAINT "lnk_Users_EmailVerif" FOREIGN KEY ( "UID" ) REFERENCES "Users"( "UID" )
);


CREATE TABLE "Favorites"(
	"FavID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	"UID" Integer NOT NULL,
	"QID" Integer NOT NULL,
	CONSTRAINT "lnk_Users_FavoritesUID" FOREIGN KEY ( "UID" ) REFERENCES "Users"( "UID" ),
	CONSTRAINT "lnk_Users_FavoritesQID" FOREIGN KEY ( "QID" ) REFERENCES "Questions"( "QID" )
);


CREATE TABLE "Comments"(
	"ComID" Integer PRIMARY KEY AUTOINCREMENT,
	"CommentedBy" Integer,
	"PostID" Integer,
	"Comment" Text,
	"CommentedDate" DateTime,
	CONSTRAINT "lnk_Posts_CommentsUID" FOREIGN KEY ( "CommentedBy" ) REFERENCES "Users"( "UID" ),
	CONSTRAINT "lnk_Posts_Comments" FOREIGN KEY ( "PostID" ) REFERENCES "Posts"( "PID" )
);


CREATE TABLE "Users"(
	"UID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	"Email" Text NOT NULL,
	"Password" Text NOT NULL,
	"AdOpt" Boolean,
	"CreatedDate" DateTime,
CONSTRAINT "PasswordLength" CHECK (LENGTH("Password") > 5) );


INSERT INTO "Users" ("UID","Email","Password","AdOpt","CreatedDate") VALUES ( 1,'onurgule@gmail.com','112233',1,'24.11.2019' );



CREATE TABLE "Badges"(
	"BID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	"BadgeName" Text NOT NULL,
	"BadgeDesc" Text );


CREATE TABLE "Messages"(
	"MID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	"FromUID" Integer NOT NULL,
	"ToUID" Integer NOT NULL,
	"Message" Text,
	"MessageDate" DateTime NOT NULL,
	CONSTRAINT "lnk_Users_Message_From" FOREIGN KEY ( "FromUID" ) REFERENCES "Users"( "UID" ),
	CONSTRAINT "lnk_Users_Message_To" FOREIGN KEY ( "ToUID" ) REFERENCES "Users"( "UID" )
);


CREATE TABLE "Preferences"(
	"PrID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	"UID" Integer NOT NULL,
	"KeyShortcuts" Boolean,
	"DisableTopNav" Boolean,
	"HideLeftNav" Boolean,
	"HideHotNewQues" Boolean,
	CONSTRAINT "lnk_Users_Preferences" FOREIGN KEY ( "UID" ) REFERENCES "Users"( "UID" )
);


CREATE TABLE "ProfileDetails"(
	"PID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	"UID" Integer NOT NULL,
	"AboutMe" Text,
	"Location" Text,
	"DisplayName" Text,
	"FullName" Text,
	"Website" Text,
	"Twitter" Text,
	"Github" Text,
	"PictureID" Integer DEFAULT 1,
	CONSTRAINT "lnk_Users_ProfileDetails" FOREIGN KEY ( "UID" ) REFERENCES "Users"( "UID" )
 );


