<?php

// Düzenleme: Domainhizmetleri.com

use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\Exception;
use PHPMailer\PHPMailer\SMTP;

// Gerekli dosyaları include ediyoruz

function mailsend($sid,$code){
	
require 'PHPMailer/PHPMailer.php';
require 'PHPMailer/Exception.php';
require 'PHPMailer/SMTP.php';

$mail = new PHPMailer(true);
//$tomail = $_GET["tomail"];
//$uid = $_GET["uid"];
//$realCode = $code;
try {
    //SMTP Sunucu Ayarları
    $mail->SMTPDebug = 0;
	$mail->CharSet = 'utf-8';										// DEBUG Kapalı: 0, DEBUG Açık: 2 // Detaylı bilgi için: https://github.com/PHPMailer/PHPMailer/wiki/SMTP-Debugging
    $mail->isSMTP();											// SMTP gönderimi kullan
    $mail->Host       = 'mail.rept.link';					// Email sunucu adresi. Genellikle mail.domainadi.com olarak kullanilir. Bu adresi hizmet saglayiciniza sorabilirsiniz
    $mail->SMTPAuth   = true;									// SMTP kullanici dogrulama kullan
    $mail->Username   = 'verification@rept.link';				// SMTP sunucuda tanimli email adresi
    $mail->Password   = 'v8CaIQIuwNKF';							// SMTP email sifresi
    $mail->SMTPSecure = PHPMailer::ENCRYPTION_SMTPS;			// SSL icin `PHPMailer::ENCRYPTION_SMTPS` kullanin. SSL olmadan 587 portundan gönderim icin `PHPMailer::ENCRYPTION_STARTTLS` kullanin
    $mail->Port       = 465;									// Eger yukaridaki deger `PHPMailer::ENCRYPTION_SMTPS` ise portu 465 olarak guncelleyin. Yoksa 587 olarak birakin
    $mail->setFrom('verification@rept.link', 'SAU FLASH'); // Gonderen bilgileri yukaridaki $mail->Username ile aynı deger olmali

    //Alici Ayarları
    $mail->addAddress($sid."@sakarya.edu.tr"); // Alıcı bilgileri
    //$mail->addReplyTo('YANITADRESI@domainadi.com');			// Alıcı'nın emaili yanıtladığında farklı adrese göndermesini istiyorsaniz aktif edin
    //$mail->addCC('CC@domainadi.com');
    //$mail->addBCC('BCC@domainadi.com');

    // Mail Ekleri
    //$mail->addAttachment('/var/tmp/file.tar.gz');         // Attachment ekleme
    //$mail->addAttachment('/tmp/image.jpg', 'new.jpg');    // Opsiyonel isim degistirerek Attachment ekleme

    // İçerik
    $mail->isHTML(true); // Gönderimi HTML türde olsun istiyorsaniz TRUE ayarlayin. Düz yazı (Plain Text) icin FALSE kullanin
    $mail->Subject = 'SAU FLASH - Giriş Kodu';
    $mail->Body    = 'SAU FLASH sistemine giriş yapabilmek için bu şifreyi kullanabilirsiniz:<br><b>'.$code.'</b><br>Bu şifre tek kullanımlıktır, tekrar giriş yapmak için emailinize yeni bir şifre gelecektir.<br><br>SAU FLASH - Sakarya Üniversitesi Mesajlaşma Ağı';

    $mail->send();
    return 1;
} catch (Exception $e) {
	error_log($e."_".$mail->ErrorInfo);
    return 0;
}

}