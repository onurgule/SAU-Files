<?php
session_name("sauchat");
session_start();
include dirname(__DIR__) ."../../config/db.php";
$uid = $_SESSION["uid"];
$gid = $_GET["gid"];
$q = $db->prepare("CALL toggleGroup(:uid,:gid)");
$q->execute(array("uid" => $uid, "gid" => $gid));
header("Location: https://onurgule.com.tr/flash/chat/");
echo "<script>document.location.href='https://onurgule.com.tr/flash/chat/';</script>";