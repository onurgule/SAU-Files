<?php
session_name("sauchat");
session_start(); 
if($_SESSION["uid"] != null && $_SESSION["uid"] != "" && $_SESSION["uid"] != 0) exit("<script>document.location.href='chat/'</script>"); 
?>
<!DOCTYPE html>
<html lang="en">

<!-- begin::Head -->
<head>
    <meta charset="utf-8" />
    <title>FLASH | Sakarya Üniversitesi Mesajlaşma Ağı</title>
    <meta name="description" content="Sakarya Üniversitesi Bilgi Sistemi">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Poppins:300,400,500,600,700|Roboto:300,400,500,600,700">
    <link href="/flash/assets/css/login-1.css" rel="stylesheet" type="text/css" />
    <link href="https://cdn0.sabis.sakarya.edu.tr/metronic/6.1.6/assets/plugins/global/plugins.bundle.css" rel="stylesheet" type="text/css" />
    <link href="https://cdn0.sabis.sakarya.edu.tr/metronic/6.1.6/assets/css/style.bundle.css" rel="stylesheet" type="text/css" />

    <link rel="shortcut icon" href="https://cdn0.sabis.sakarya.edu.tr/saulogo/favicon.ico" />
</head>

<!-- end::Head -->
<!-- begin::Body -->
<body class="kt-quick-panel--right kt-demo-panel--right kt-offcanvas-panel--right kt-header--fixed kt-header-mobile--fixed kt-subheader--enabled kt-subheader--fixed kt-subheader--solid kt-aside--enabled kt-aside--fixed kt-page--loading">

    <!-- begin:: Page -->
    <div class="kt-grid kt-grid--ver kt-grid--root">
        <div class="kt-grid kt-grid--hor kt-grid--root  kt-login kt-login--v1" id="kt_login">
            <div class="kt-grid__item kt-grid__item--fluid kt-grid kt-grid--desktop kt-grid--ver-desktop kt-grid--hor-tablet-and-mobile">
                <!--begin::Aside-->
                <div class="kt-grid__item kt-grid__item--order-tablet-and-mobile-2 kt-grid kt-grid--hor kt-login__aside gol1" id="kt-login__aside">
                    <div class="kt-grid__item" id="logo-back">
                        <a href="https://sakarya.edu.tr" target="_blank" class="kt-login__logo">
                            <img src="https://cdn0.sabis.sakarya.edu.tr/logo/1.0.0/logo.svg" id="login-logo" />
                        </a>
                    </div>
                    <div class="kt-grid__item kt-grid__item--fluid kt-grid kt-grid--ver">
                        <div class="kt-grid__item kt-grid__item--middle">


                            <ul class="servis-listesi">
								<li>
                                    <a href="http://sabis.sakarya.edu.tr" target="_blank"><i class="fa fa-user-graduate"></i> SABIS</a>
                                </li>
                                <li>
                                    <a href="http://menu.sabis.sakarya.edu.tr" target="_blank"><i class="fa fa-utensils"></i> Yemek Menüsü</a>
                                </li>
                                <li>
                                    <a href="http://ogrisl.sakarya.edu.tr/tr/icerik/8861/32698/akademik-takvim" target="_blank"><i class="fa fa-calendar-alt"></i> Akademik Takvim</a>
                                </li>
                                <li>
                                    <a href="https://rehber.sakarya.edu.tr" target="_blank"><i class="fa fa-phone"></i> Telefon Rehberi</a>
                                </li>
                                <li>
                                    <a href="http://kutuphane.sakarya.edu.tr" target="_blank"><i class="fa fa-book"></i> Kütüphane</a>
                                </li>
                                <li>
                                    <a href="http://ogrisl.sakarya.edu.tr" target="_blank"><i class="fa fa-user-graduate"></i> Öğrenci İşleri</a>
                                </li>
                            </ul>
                        </div>
                    </div>
                    <div class="kt-grid__item">
                        <div class="kt-login__info">
                            <div class="kt-login__copyright">
                                &copy 2021 G171210021 - G171210375
                            </div>
                            <div class="kt-login__menu">

                            </div>
                        </div>
                    </div>
                </div>


<div class="kt-grid__item kt-grid__item--fluid  kt-grid__item--order-tablet-and-mobile-1  kt-login__wrapper" id="sag-back">
    <div class="kt-login__body">

        <div class="kt-login__form">
            <div class="kt-login__title">
			<a href="#" class="kt-login__logo">
                <img src="assets/img/flash.png" id="login-logo" style="height:150px;" />
            </a>
                <h1 class="kurumsal-renk">
                    SAU FLASH
                </h1>
                <h2 class="kurumsal-renk">
                    Sakarya Üniversitesi <br>Mesajlaşma Ağı
                </h2>
            </div>
			<!--<p>o:<? print_r($_SESSION);?></p>-->
            <form class="kt-form" id="kt_login_form">
                <div class="form-group">
                    <input style="background-color:#ccc;" class="form-control" placeholder="Öğrenci Numarası" autocomplete="off" autofocus type="text" data-val="true" data-val-required="Öğrenci numarası girilmelidir." id="sid" name="sid" value="">
                </div>
                <div class="form-group input-pass" style="display:none;">
                    <input type="password" class="form-control" placeholder="Emailinize Gelen Kod" autocomplete="off" data-val="true" data-val-required="The Password field is required." id="pass" name="pass">
                </div>

                <div class="kt-login__actions">
                    <button type="button" onclick="tryToLogin()" name="button" value="login" class="btn btn-primary btn-elevate kt-login__btn-primary">Giriş Yap</button>
                </div>

            <input name="csrftoken" type="hidden" value="" />
			</form>
        </div>
    </div>
</div>
            </div>
        </div>
    </div>
	<script src="https://code.jquery.com/jquery-3.6.0.min.js" integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4=" crossorigin="anonymous"></script>
	<script>
	function tryToLogin(){
		if($('.input-pass')[0].style.display == 'none'){
		var sid = $('#sid').val();
		$.post("api/user/tryToLogin.php", {sid: sid}, function(res){
			let result = JSON.parse(res);
			console.log(result);
			if(result.result == 'success'){
				$('.input-pass').show();
			}
			else{
				alert(result.result);
				//swal2 olacak.
			}
		  });
		}
		else{
		var sid = $('#sid').val();
		var pass = $('#pass').val();
		$.post("api/user/tryToLogin.php", {sid: sid, pass:pass}, function(res){
			let result = JSON.parse(res);
			if(result.result == 'success'){
				document.location.href = 'chat/';
			}
			else{
				alert(result.result);
				//swal2 olacak.
			}
		  });
			
		}
	}
	</script>
</body>
</html>