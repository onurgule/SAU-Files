<?
class User{
		private $uid;
		private $sid;
		private $token;
		private $nick;
		private $connid;
		
		public function __construct(){
			
		}
		public static function withToken($token){
			$instance = new self();
			$instance->token = $token;
			$instance->updateFromToken();
			return $instance;
		}
		public static function withUID($uid){
			$instance = new self();
			$instance->uid = $uid;
			$instance->updateFromUid();
			return $instance;
		}
		public static function withConn($conn){
			$instance = new self();
			$instance->connid = $conn;
			$instance->updateFromConn();
			return $instance;
		}
		public function setUID($userid){
			$this->uid = $userid;
		}
		public function getUID(){
			return $this->uid;
		}
		public function setSID($studentid){
			$this->sid = $studentid;
		}
		public function getSID(){
			return $this->sid;
		}
		public function setToken($token){
			$this->token = $token;
		}
		public function getToken(){
			return $this->token;
		}
		public function setNick($nickname){
			$this->nick = $nickname;
		}
		public function getNick(){
			return $this->nick;
		}
		public function setConnID($connid){
			$this->connid = $connid;
		}
		public function getConnID(){
			return $this->connid;
		}
		public function updateFromToken(){
			include dirname(__DIR__)."/config/db.php";
			$q = $db->prepare("CALL getUidFromToken(:token)");
			$q->execute(array("token" => $this->token));
			$f = $q->fetch(PDO::FETCH_ASSOC);
			$this->uid = $f["UID"];
			$this->sid = $f["SID"];
			$this->nick = $f["Nickname"];
			$this->connid = $f["connection_id"];
		}
		public function updateFromUid(){
			include dirname(__DIR__)."/config/db.php";
			$q = $db->prepare("CALL getConnFromUID(:uid)");
			$q->execute(array("uid" => $this->uid));
			$f = $q->fetch(PDO::FETCH_ASSOC);
			$this->uid = $f["UID"];
			$this->sid = $f["SID"];
			$this->nick = $f["Nickname"];
			$this->connid = $f["connection_id"];
		}
		public function updateFromConn(){
			include dirname(__DIR__)."/config/db.php";
			$q = $db->prepare("CALL getUserFromConn(:conn)");
			$q->execute(array("conn" => $this->connid));
			$f = $q->fetch(PDO::FETCH_ASSOC);
			$this->uid = $f["UID"];
			$this->sid = $f["SID"];
			$this->nick = $f["Nickname"];
			$this->connid = $f["connection_id"];
		}
		public function deleteToken(){
			include dirname(__DIR__)."/config/db.php";
			$q = $db->prepare("CALL setToken(:uid,:token,0)");
			$q->execute(array("uid"=>$this->uid,"token" => $this->token));
		}
		public function setConnToDb($token){
			include dirname(__DIR__)."/config/db.php";
			$q = $db->prepare("CALL setConn(:token,:conn)");
			print_r(array("token" => $this->token,"conn" => $this->connid));
			$q->execute(array("token" => $this->token,"conn" => $this->connid));
		}
}