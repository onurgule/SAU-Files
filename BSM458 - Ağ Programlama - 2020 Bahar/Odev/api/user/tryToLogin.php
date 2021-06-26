<?php
session_name("sauchat");
session_start();
$sid = $_POST["sid"];
if(isset($_POST["pass"])){
	$code = $_POST["pass"];
	include "../../config/db.php";
	$q = $db->prepare("CALL loginUser(:sid,:code)");
	if($q->execute(array("sid" => $sid, "code" => $code))){
		$f = $q->fetch(PDO::FETCH_ASSOC);
		if($f["result"] == "success"){
			$_SESSION["uid"] = $f["UID"];
			$_SESSION["sid"] = $f["SID"];
			$_SESSION["nickname"] = $f["Nickname"];
			echo json_encode(array("result" => "success"));
		}
		else if($f["result"] == "wrong-password"){
			echo json_encode(array("result" => "wrong-password"));
		}
		else echo json_encode(array("result" => "error"));
	}
	else echo json_encode(array("result" => "error-exec"));
	//gerçekten login
	//doğruysa sessiona yaz result:success yolla, yanlışsa result:wrong-code yolla.
}
else{
	include "../../config/db.php";
	$sid = str_replace(".","",$sid);
	$sid = str_replace(" ","",$sid);
	$sid = strtoupper($sid);
	$q = $db->prepare("CALL tryToLoginUser(:sid,:code)");
	$code = mt_rand(134152, 986742);
	if($q->execute(array("sid" => $sid, "code" => $code))){
	$f = $q->fetch(PDO::FETCH_ASSOC);
		if($f["result"] == "success"){
			include "../mail/mailSender.php";
			mailsend($sid,$code);
			echo json_encode(array("result" => "success"));
			//email gönder. $sid."@sakarya.edu.tr"
		}
		else if($f["result"] == "time-limit"){
			echo json_encode(array("result" => "time-limit"));
		}
		else echo json_encode(array("result" => "error"));
	}
	else echo json_encode(array("result" => "error"));
	//code gönder emaile try
	//prosedure her 5 dkda bir yapılsın ekle
	//5 dk sıkıntı olursa prosedürden result:time-limit gelsin, buradan da aynısını yollarız.
}