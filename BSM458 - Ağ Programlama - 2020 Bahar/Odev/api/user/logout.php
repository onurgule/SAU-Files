<?php
session_name("sauchat");
session_start();

session_destroy();
header('Location: https://onurgule.com.tr/flash/');
echo "<script>document.location.href='https://onurgule.com.tr/flash/';</script>";