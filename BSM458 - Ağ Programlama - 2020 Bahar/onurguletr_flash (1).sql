-- phpMyAdmin SQL Dump
-- version 4.9.5
-- https://www.phpmyadmin.net/
--
-- Anamakine: localhost:3306
-- Üretim Zamanı: 15 May 2021, 00:21:27
-- Sunucu sürümü: 10.2.37-MariaDB-cll-lve
-- PHP Sürümü: 7.3.27

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Veritabanı: `onurguletr_flash`
--

DELIMITER $$
--
-- Yordamlar
--
CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `changeNick` (IN `fuid` INT, IN `fnick` VARCHAR(60) CHARSET utf8)  NO SQL
BEGIN
UPDATE Users u SET u.Nickname = fnick WHERE u.UID = fuid;
END$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `getConnFromUid` (IN `fuid` INT)  NO SQL
SELECT *,(SELECT ut.connection_id FROM UserTokens ut WHERE ut.UID = fuid ORDER BY ut.UTID DESC LIMIT 0,1) AS connection_id FROM Users u WHERE u.UID = fuid$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `getGroups` (IN `fuid` INT)  NO SQL
SELECT *,(SELECT COUNT(*) FROM GroupUsers gu WHERE gu.GID = g.GID AND gu.UID = fuid AND gu.Enabled = 1) AS 'inside' FROM Groups g WHERE g.Enabled = 1 AND g.GID AND g.GID <> 1$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `getGroupUsers` (IN `fgid` INT)  NO SQL
BEGIN
IF fgid = 0 OR fgid = 1 THEN
SELECT u.UID,getConnByUid(u.UID) AS connection_id FROM Users u WHERE getConnByUid(u.UID) IS NOT NULL;
ELSE
SELECT gu.UID,getConnByUid(gu.UID) AS 'connection_id' FROM GroupUsers gu WHERE gu.GID = fgid AND gu.Enabled = 1;
END IF;
END$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `getLastMessagePages` (IN `fuid` INT)  NO SQL
SELECT m.Type,m.Receiver FROM Messages m WHERE (m.Type = 1 AND (m.Receiver = fuid OR m.UID = fuid)) OR (m.Type = 2 AND (m.Receiver IN (SELECT gu.GID FROM GroupUsers gu WHERE gu.UID = fuid AND gu.Enabled = 1) OR m.UID = fuid)) GROUP BY m.Type, m.Receiver$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `getMessages` (IN `fuid` INT, IN `ftype` INT, IN `frec` INT)  NO SQL
BEGIN 
SELECT *,(SELECT u.Nickname FROM Users u WHERE u.UID = m.UID) AS Nick FROM Messages m WHERE m.Type = ftype AND (m.Type = 1 AND (m.Receiver = frec OR m.Receiver = fuid)) OR ((m.Type = 0 OR m.Type = 2) AND (m.Receiver = frec));
END$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `getPeople` (IN `fuid` INT)  NO SQL
(SELECT 0 AS Type,0 AS Kisi, 'Broadcast' AS Name, 'Genel' AS Small) #Broadcast
UNION DISTINCT
(SELECT DISTINCT m.Type AS Type,(IF(m.Receiver = fuid, m.UID,m.Receiver)) AS Kisi, IF(m.Type = 1,(SELECT Nickname FROM Users WHERE UID = Kisi), (SELECT Name FROM Groups WHERE GID = Kisi)) AS Name, (IF(m.Type = 2,'Grup',(SELECT u.SID FROM Users u WHERE u.UID = Kisi))) AS Small FROM Messages m WHERE (m.Type = 1 AND (m.Receiver = fuid OR m.UID = fuid)) OR (m.Type = 2 AND (m.Receiver IN (SELECT gu.GID FROM GroupUsers gu WHERE gu.UID = fuid AND gu.Enabled = 1) OR (m.UID = fuid AND m.UID IN (SELECT gu.GID FROM GroupUsers gu WHERE gu.UID = fuid AND gu.Enabled = 1)))) GROUP BY m.Type, m.Receiver ORDER BY MAX(m.MID) DESC)
UNION DISTINCT
SELECT 2 AS Type, g.GID AS Kisi, g.Name AS Name, 'Grup' AS Small FROM Groups g INNER JOIN GroupUsers gu ON g.GID = gu.GID WHERE gu.UID = fuid AND gu.Enabled = 1
UNION DISTINCT
(SELECT DISTINCT 1 AS Type,UID AS Kisi, (SELECT u.Nickname FROM Users u WHERE u.UID = Kisi LIMIT 0,1) AS Name, (SELECT u.SID FROM Users u WHERE u.UID = Kisi LIMIT 0,1) AS Small FROM UserTokens WHERE UID <> fuid ORDER BY UTID DESC)$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `getUidFromToken` (IN `ftoken` VARCHAR(20))  NO SQL
SELECT *,(SELECT ut.connection_id FROM UserTokens ut WHERE ut.Token = ftoken LIMIT 0,1) AS 'connection_id' FROM Users u WHERE u.UID = (SELECT ut.UID FROM UserTokens ut WHERE ut.Token = ftoken LIMIT 0,1)$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `getUnseenMessages` (IN `fuid` INT, IN `ftype` INT, IN `frec` INT)  NO SQL
BEGIN 
SET @last_date = (SELECT s.seen_date FROM Seen s WHERE s.UID = fuid AND s.MType = ftype AND s.MReceiver = frec ORDER BY s.SID DESC LIMIT 0,1);
SELECT * FROM Messages m WHERE ((m.Type = ftype AND m.Receiver = frec) OR (m.Type = 1 AND m.Receiver = fuid)) AND m.Date > @last_date;
END$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `getUserFromConn` (IN `fconn` INT)  NO SQL
SELECT *,(SELECT ut.connection_id FROM UserTokens ut WHERE ut.connection_id = fconn ORDER BY ut.UTID DESC LIMIT 0,1) AS connection_id FROM Users u WHERE u.UID = (SELECT ut.UID FROM UserTokens ut WHERE ut.connection_id = fconn ORDER BY ut.UTID DESC LIMIT 0,1)$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `loginUser` (IN `fsid` VARCHAR(80), IN `fcode` INT)  NO SQL
BEGIN
SET @ishere = (SELECT COUNT(*) FROM Users u WHERE u.SID = fsid AND u.Code = fcode);
IF @ishere>0 THEN
SELECT *, 'success' AS 'result' FROM Users u WHERE u.SID = fsid AND u.Code = fcode; 
ELSE
SELECT 'wrong-password' AS 'result';
END IF;
END$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `seeMessages` (IN `fuid` INT, IN `ftype` INT, IN `frec` INT)  NO SQL
BEGIN
INSERT INTO Seen(UID,MType,MReceiver) VALUES(fuid,ftype,frec);
END$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `sendMessage` (IN `fuid` INT, IN `fmtype` INT, IN `freceiver` INT, IN `fmsg` VARCHAR(250) CHARSET utf8)  NO SQL
BEGIN
INSERT INTO Messages(UID,Message,Type,Receiver) VALUES(fuid,fmsg,fmtype,freceiver);
END$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `setConn` (IN `ftoken` VARCHAR(20), IN `fconn` INT)  NO SQL
UPDATE UserTokens ut SET ut.connection_id = fconn WHERE ut.Token = ftoken$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `setToken` (IN `fuid` INT, IN `ftoken` VARCHAR(20), IN `online` INT)  NO SQL
BEGIN
IF online = 1 THEN
#DELETE FROM UserTokens WHERE UID = fuid;
INSERT INTO UserTokens(UID,Token) VALUES(fuid, ftoken);
ELSE
UPDATE UserTokens SET enabled = 0 WHERE UID = fuid;
END IF;
END$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `toggleGroup` (IN `fuid` INT, IN `fgid` INT)  NO SQL
BEGIN
SET @isinside = (SELECT COUNT(*) FROM GroupUsers gu WHERE gu.GID = fgid AND gu.UID = fuid);
IF @isinside > 0 THEN
UPDATE GroupUsers gu SET gu.Enabled = !gu.Enabled WHERE gu.GID = fgid AND gu.UID = fuid;
ELSE
INSERT INTO GroupUsers(GID,UID) VALUES(fgid,fuid);
END IF;
END$$

CREATE DEFINER=`onurguletr`@`localhost` PROCEDURE `tryToLoginUser` (IN `fsid` VARCHAR(80), IN `fcode` INT)  NO SQL
    COMMENT 'sid giren usera code eklenir, mail atılır'
BEGIN
SET @ishere = (SELECT COUNT(*) FROM Users u WHERE u.SID = fsid);
SET @code_date = (SELECT u.code_date FROM Users u WHERE u.SID = fsid);
IF @code_date IS NULL OR @code_date < NOW() - INTERVAL 10 MINUTE THEN
IF @ishere > 0 THEN
UPDATE Users u SET u.Code = fcode, u.code_date = NOW() WHERE u.SID = fsid;
SELECT 'success' AS 'result';
ELSE
INSERT INTO Users(SID,Nickname,`Code`,code_date) VALUES(fsid,fsid,fcode,NOW());
SELECT 'success' AS 'result';
END IF;
ELSE
SELECT 'time-limit' AS 'result';
END IF;
END$$

--
-- İşlevler
--
CREATE DEFINER=`onurguletr`@`localhost` FUNCTION `getConnByUid` (`fuid` INT) RETURNS INT(11) NO SQL
RETURN (SELECT ut.connection_id FROM UserTokens ut WHERE ut.UID = fuid ORDER BY ut.UTID DESC LIMIT 0,1)$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Groups`
--

CREATE TABLE `Groups` (
  `GID` int(11) NOT NULL,
  `Name` varchar(60) CHARACTER SET utf8 COLLATE utf8_turkish_ci NOT NULL,
  `Enabled` int(11) NOT NULL DEFAULT 1,
  `creation_date` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Tablo döküm verisi `Groups`
--

INSERT INTO `Groups` (`GID`, `Name`, `Enabled`, `creation_date`) VALUES
(1, 'Broadcast', 1, '2021-04-04 07:38:50'),
(2, 'Bilgisayar Mühendisliği', 1, '2021-04-04 17:29:14'),
(3, 'Ağ Programlama', 1, '2021-04-04 18:14:55'),
(4, 'Pratikte BT ve BS', 1, '2021-04-04 18:14:55'),
(5, 'Yazılım Testi', 1, '2021-04-04 18:14:55'),
(6, 'Derin Öğrenme', 1, '2021-04-04 18:14:55');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `GroupUsers`
--

CREATE TABLE `GroupUsers` (
  `GUID` int(11) NOT NULL,
  `GID` int(11) NOT NULL,
  `UID` int(11) NOT NULL,
  `Enabled` int(11) NOT NULL DEFAULT 1,
  `added_date` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Tablo döküm verisi `GroupUsers`
--

INSERT INTO `GroupUsers` (`GUID`, `GID`, `UID`, `Enabled`, `added_date`) VALUES
(1, 2, 1, 1, '2021-04-04 17:29:39'),
(2, 3, 1, 1, '2021-04-04 18:57:56'),
(3, 3, 2, 1, '2021-04-05 20:42:40'),
(4, 5, 1, 1, '2021-05-06 17:24:09'),
(5, 5, 2, 1, '2021-05-06 17:24:29'),
(6, 6, 2, 1, '2021-05-06 21:22:40'),
(7, 6, 1, 0, '2021-05-06 21:22:49');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Messages`
--

CREATE TABLE `Messages` (
  `MID` int(11) NOT NULL,
  `UID` int(11) NOT NULL,
  `Message` varchar(250) CHARACTER SET utf8 COLLATE utf8_turkish_ci NOT NULL,
  `Type` int(11) NOT NULL COMMENT '0:broadcast,1:touid,2:togroup',
  `Receiver` int(11) NOT NULL DEFAULT 0 COMMENT '0:broadcast, else:uid or group by type',
  `Date` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Tablo döküm verisi `Messages`
--

INSERT INTO `Messages` (`MID`, `UID`, `Message`, `Type`, `Receiver`, `Date`) VALUES
(1, 1, 'Merhaba', 0, 0, '2021-04-04 15:27:07'),
(2, 2, 'Selam', 0, 0, '2021-04-04 15:28:40'),
(3, 1, 'Ee çalışıyor mu bu', 0, 0, '2021-04-04 15:28:45'),
(4, 1, 'Valla çalışıyor gibi', 0, 0, '2021-04-04 15:28:53'),
(5, 1, 'sa', 0, 0, '2021-04-04 15:35:36'),
(6, 1, 'test', 0, 0, '2021-04-04 15:36:11'),
(7, 2, 'Şimdi', 1, 1, '2021-04-04 15:48:44'),
(8, 2, 'Eveeet', 1, 1, '2021-04-04 16:26:38'),
(9, 1, 'Çalışmıyor mu burası?', 1, 2, '2021-04-04 16:35:31'),
(10, 2, 'Çalışıyor gibi', 1, 1, '2021-04-04 16:35:37'),
(11, 1, 'Selam kardeşim', 1, 2, '2021-04-04 16:39:53'),
(12, 1, 'Selammm', 1, 2, '2021-04-04 16:41:29'),
(13, 1, 'Naber', 1, 2, '2021-04-04 16:41:32'),
(14, 2, 'iyidir', 1, 1, '2021-04-04 16:41:42'),
(15, 2, 'nasıl yanii', 1, 1, '2021-04-04 16:41:58'),
(16, 2, 'testttt', 1, 1, '2021-04-04 16:43:32'),
(17, 2, 'test2', 1, 1, '2021-04-04 16:43:38'),
(18, 1, 'Selamm', 1, 2, '2021-04-04 17:00:17'),
(19, 1, 'Buradan', 0, 0, '2021-04-04 17:00:24'),
(20, 1, 'hocam offline olmuşun ayıp', 1, 2, '2021-04-04 17:07:48'),
(21, 2, 'geldim hocam', 1, 1, '2021-04-04 17:07:58'),
(22, 2, 'test scroll', 1, 1, '2021-04-04 17:08:24'),
(23, 2, 'gelenlerrr', 1, 1, '2021-04-04 17:09:23'),
(24, 1, 'aynenn', 1, 2, '2021-04-04 17:09:28'),
(25, 2, 'aga yaa', 1, 1, '2021-04-04 17:22:39'),
(26, 2, 'sa', 1, 1, '2021-04-04 17:23:25'),
(27, 2, 'ss', 0, 0, '2021-04-04 17:23:31'),
(28, 1, 'ass', 0, 0, '2021-04-04 17:23:37'),
(29, 1, 'Test group', 2, 2, '2021-04-04 17:58:26'),
(30, 1, 'Testt', 2, 2, '2021-04-04 18:00:08'),
(31, 1, 'bm test', 2, 2, '2021-04-04 18:00:43'),
(32, 1, 'bmm', 2, 2, '2021-04-04 18:01:37'),
(33, 1, 'çalış artık çalış', 2, 2, '2021-04-04 18:03:52'),
(34, 1, 'işte bu', 2, 2, '2021-04-04 18:03:55'),
(35, 1, 'Ödevin gereklilikleri şu an itibariyle tamamlandı. ', 2, 3, '2021-04-04 19:02:46'),
(36, 1, 'Yukarıya daha düzgün profil, nick değişikliği, çıkış butonu vs. kaldı.', 2, 3, '2021-04-04 19:07:32'),
(37, 1, 'hocam gel de test edelim', 1, 2, '2021-04-05 20:14:51'),
(38, 2, 'test', 0, 0, '2021-04-05 20:32:58'),
(39, 1, 'oh be', 1, 2, '2021-04-05 20:41:26'),
(40, 1, 'sonunda hocam', 1, 2, '2021-04-05 20:41:35'),
(41, 2, 'vay', 0, 0, '2021-04-05 20:41:36'),
(42, 2, 'fena bi chat ortamı', 0, 0, '2021-04-05 20:41:42'),
(43, 2, 'sanarsın ICQ', 0, 0, '2021-04-05 20:41:45'),
(44, 1, 'hocam', 0, 0, '2021-04-05 20:41:47'),
(45, 1, 'burası genel', 0, 0, '2021-04-05 20:41:48'),
(46, 1, 'özele gel', 0, 0, '2021-04-05 20:41:51'),
(47, 2, 'ok', 0, 0, '2021-04-05 20:41:54'),
(48, 2, 'brb', 0, 0, '2021-04-05 20:41:58'),
(49, 2, 'vay beeeee', 1, 1, '2021-04-05 20:42:04'),
(50, 2, 'nick değiştir falan', 1, 1, '2021-04-05 20:42:19'),
(51, 1, 'tabi hocam', 1, 2, '2021-04-05 20:42:23'),
(52, 1, 'fena ortam', 1, 2, '2021-04-05 20:42:25'),
(53, 2, 'burda millet kovalasın', 1, 1, '2021-04-05 20:42:32'),
(54, 1, 'ağ programlama grubuna girsene', 1, 2, '2021-04-05 20:42:36'),
(55, 2, 'vayyyyy', 2, 3, '2021-04-05 20:42:46'),
(56, 1, 'aaa senin mesajlar kayboluyo', 1, 2, '2021-04-05 20:43:02'),
(57, 2, 'nasii', 1, 1, '2021-04-05 20:43:06'),
(58, 1, 'sessionlarda problem var dbye atamıyorsun mesajları :d', 1, 2, '2021-04-05 20:43:13'),
(59, 2, 'ahahahah', 1, 1, '2021-04-05 20:43:25'),
(60, 1, 'özeldeki mesajların kayboluyor bence :d', 1, 2, '2021-04-05 20:43:26'),
(61, 1, 'bence', 1, 2, '2021-04-05 20:43:27'),
(62, 1, 'bende', 1, 2, '2021-04-05 20:43:29'),
(63, 1, 'hg', 2, 3, '2021-04-05 20:43:36'),
(64, 1, 'sadece özel ama ilginç :d', 1, 2, '2021-04-05 20:43:43'),
(65, 2, 'haha', 1, 1, '2021-04-05 20:43:47'),
(66, 2, 'digerleri duruyo he', 1, 1, '2021-04-05 20:43:52'),
(67, 2, 'yeter hocam', 1, 1, '2021-04-05 20:43:55'),
(68, 2, 'salla', 1, 1, '2021-04-05 20:43:56'),
(69, 1, 'aynen', 1, 2, '2021-04-05 20:43:56'),
(70, 1, 'tabi hocam h', 1, 2, '2021-04-05 20:44:03'),
(71, 2, 'kim ne bilcek', 1, 1, '2021-04-05 20:44:07'),
(72, 1, 'hocanın istediği her şeyi ekledim', 1, 2, '2021-04-05 20:44:08'),
(73, 2, 'snapchat gibi ', 1, 1, '2021-04-05 20:44:10'),
(74, 1, 'yok yok eklerim', 1, 2, '2021-04-05 20:44:12'),
(75, 2, 'daha iyi hem', 1, 1, '2021-04-05 20:44:14'),
(76, 1, 'düzeltirim yani', 1, 2, '2021-04-05 20:44:18'),
(77, 1, 'bişi değil', 1, 2, '2021-04-05 20:44:19'),
(78, 1, 'eskiden olamyan hata olması ilginç :d', 1, 2, '2021-04-05 20:44:25'),
(79, 2, 'belki edgeden kaynaklıdır', 1, 1, '2021-04-05 20:44:32'),
(80, 1, 'idk', 1, 2, '2021-04-05 20:44:59'),
(81, 1, 'bidakka', 1, 2, '2021-04-05 20:45:17'),
(82, 1, 'sen de görememen lazım beni mantıken', 1, 2, '2021-04-05 20:45:23'),
(83, 1, 'eski mesajları', 1, 2, '2021-04-05 20:45:27'),
(84, 2, 'ben her şeyi görüyom', 1, 1, '2021-04-05 20:45:52'),
(85, 1, 'başka gruba girip tekrar buraya girince görebiliyon mu bneimkileri', 1, 2, '2021-04-05 20:46:05'),
(86, 2, 'eet', 1, 1, '2021-04-05 20:46:08'),
(87, 2, 'hatta', 1, 1, '2021-04-05 20:46:13'),
(88, 2, 'en eskiler bile duruyo', 1, 1, '2021-04-05 20:46:17'),
(89, 2, 'Şimdi  2021-04-04 18:48:44 Eveeet  2021-04-04 19:26:38 sunil Çalışmıyor mu burası?  Onurgule - 2021-04-04 19:35:31', 1, 1, '2021-04-05 20:46:26'),
(90, 2, '', 1, 1, '2021-04-05 20:46:26'),
(91, 1, 'heee', 1, 2, '2021-04-05 20:46:39'),
(92, 1, 'okey okey', 1, 2, '2021-04-05 20:46:40'),
(93, 1, 'benlikmiş skıntı', 1, 2, '2021-04-05 20:46:48'),
(94, 1, 'sabahtan kalma sessionla konuşuyorum da ', 1, 2, '2021-04-05 20:47:01'),
(95, 1, 'düzeldi şimdi yaz bakim bişi', 1, 2, '2021-04-05 20:47:06'),
(96, 2, 'yazıyorm', 1, 1, '2021-04-05 20:47:23'),
(97, 2, 'tekrardan', 1, 1, '2021-04-05 20:47:25'),
(98, 2, 'deneme 1', 1, 1, '2021-04-05 20:47:29'),
(99, 1, 'ben en iyisi titreşim özelliği de ekleyeyim msndeki gibi hahah', 1, 2, '2021-04-05 20:47:31'),
(100, 2, 'hahahahahaha', 1, 1, '2021-04-05 20:47:35'),
(101, 1, 'aynen düzelmiş', 1, 2, '2021-04-05 20:47:36'),
(102, 2, 'oynayan gifler', 1, 1, '2021-04-05 20:47:43'),
(103, 1, 'hmm acaba nasıl olur', 1, 2, '2021-04-05 20:47:44'),
(104, 2, 'ekranı kaplayan', 1, 1, '2021-04-05 20:47:46'),
(105, 1, 'hocam soldan bak bakim offline olcam mı', 1, 2, '2021-04-05 20:48:39'),
(106, 2, 'okey', 1, 1, '2021-04-05 20:48:43'),
(107, 2, 'oldun', 1, 1, '2021-04-05 20:48:47'),
(108, 1, 'oo süper :d', 1, 2, '2021-04-05 20:48:53'),
(109, 2, 'düzeldi', 1, 1, '2021-04-05 20:48:54'),
(110, 2, 'heheh', 1, 1, '2021-04-05 20:48:58'),
(111, 2, 'ne dinliyor', 1, 1, '2021-04-05 20:49:02'),
(112, 1, 'tamam bitmiş proje', 1, 2, '2021-04-05 20:49:03'),
(113, 1, 'hahaha ne dinliyor eklemeyelim :d', 1, 2, '2021-04-05 20:49:12'),
(114, 2, 'haha', 1, 1, '2021-04-05 20:49:21'),
(115, 1, 'bak en aşağıda ne yazıyo', 1, 2, '2021-04-05 20:49:23'),
(116, 2, 'oooo', 1, 1, '2021-04-05 20:49:28'),
(117, 2, 'fenasın', 1, 1, '2021-04-05 20:49:30'),
(118, 1, 'tamam bi ara bunun videosunu çeker yollarız', 1, 2, '2021-04-05 20:49:52'),
(119, 2, 'okeyto', 1, 1, '2021-04-05 20:49:56'),
(120, 1, 'şimdi soketi kapatıcam bakalım nolcak', 1, 2, '2021-04-05 20:50:07'),
(121, 1, 'Selam', 1, 2, '2021-05-06 17:08:30'),
(122, 1, 'Çıktın mı yaw :D', 1, 2, '2021-05-06 17:23:21'),
(123, 2, 'yok yok', 1, 1, '2021-05-06 17:23:40'),
(124, 1, 'Vize\'den 100 alanlar burada mı :d', 2, 5, '2021-05-06 17:24:23'),
(125, 2, 'Güzel gidiyor', 2, 3, '2021-05-06 17:33:17'),
(126, 2, 'kg :D', 2, 5, '2021-05-06 17:34:06'),
(127, 1, 'Merhaba', 1, 2, '2021-05-06 21:22:15'),
(128, 1, 'Offlinesin', 1, 2, '2021-05-06 21:22:27'),
(129, 2, 'Derin', 2, 6, '2021-05-06 21:22:45'),
(130, 1, 'Evet', 2, 6, '2021-05-06 21:22:53'),
(131, 1, 'Selam', 0, 0, '2021-05-06 21:23:11');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Seen`
--

CREATE TABLE `Seen` (
  `SID` int(11) NOT NULL,
  `UID` int(11) NOT NULL,
  `MType` int(11) NOT NULL,
  `MReceiver` int(11) NOT NULL,
  `seen_date` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Tablo döküm verisi `Seen`
--

INSERT INTO `Seen` (`SID`, `UID`, `MType`, `MReceiver`, `seen_date`) VALUES
(1, 1, 0, 0, '2021-04-04 15:30:16');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Users`
--

CREATE TABLE `Users` (
  `UID` int(11) NOT NULL,
  `SID` varchar(50) NOT NULL COMMENT 'Student Number or professor name',
  `Nickname` varchar(80) CHARACTER SET utf8 COLLATE utf8_turkish_ci NOT NULL,
  `Code` int(11) DEFAULT NULL COMMENT 'LoginCode',
  `code_date` timestamp NULL DEFAULT NULL,
  `register_date` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Tablo döküm verisi `Users`
--

INSERT INTO `Users` (`UID`, `SID`, `Nickname`, `Code`, `code_date`, `register_date`) VALUES
(1, 'G171210021', 'Onur', 342177, '2021-05-06 21:20:45', '2021-04-03 12:28:48'),
(2, 'G171210375', 'Fek', 631322, '2021-04-05 20:41:10', '2021-04-04 06:57:54');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `UserTokens`
--

CREATE TABLE `UserTokens` (
  `UTID` int(11) NOT NULL,
  `UID` int(11) NOT NULL,
  `Token` varchar(20) NOT NULL,
  `connection_id` varchar(35) NOT NULL,
  `enabled` int(11) NOT NULL DEFAULT 1,
  `Date` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Tablo döküm verisi `UserTokens`
--

INSERT INTO `UserTokens` (`UTID`, `UID`, `Token`, `connection_id`, `enabled`, `Date`) VALUES
(171, 2, '60699c321b659', '105', 0, '2021-04-04 11:00:02'),
(173, 1, '60699c34e9752', '117', 0, '2021-04-04 11:00:04'),
(172, 2, '60699c33d4bd1', '112', 0, '2021-04-04 11:00:03'),
(176, 2, '60699d9f224d6', '168', 0, '2021-04-04 11:06:07'),
(174, 2, '60699c361b940', '124', 0, '2021-04-04 11:00:06'),
(175, 2, '60699c9ce84fa', '137', 0, '2021-04-04 11:01:48'),
(177, 2, '60699dceb9c31', '182', 0, '2021-04-04 11:06:54'),
(178, 2, '60699ea41322a', '', 0, '2021-04-04 11:10:28'),
(179, 2, '60699eb4b1780', '', 0, '2021-04-04 11:10:44'),
(180, 2, '60699ececf66a', '49', 0, '2021-04-04 11:11:10'),
(181, 1, '60699ed4670cf', '82', 0, '2021-04-04 11:11:16'),
(182, 2, '60699f1de7078', '102', 0, '2021-04-04 11:12:29'),
(183, 1, '60699f26eeaed', '110', 0, '2021-04-04 11:12:38'),
(196, 1, '6069a128129fd', '154', 0, '2021-04-04 11:21:12'),
(184, 2, '60699f51a9589', '49', 0, '2021-04-04 11:13:21'),
(195, 2, '6069a123dd3df', '147', 0, '2021-04-04 11:21:07'),
(185, 1, '60699f524f227', '82', 0, '2021-04-04 11:13:22'),
(186, 2, '60699f7c4c4c2', '49', 0, '2021-04-04 11:14:04'),
(187, 1, '60699f7d5facd', '82', 0, '2021-04-04 11:14:05'),
(188, 2, '60699f9292b11', '49', 0, '2021-04-04 11:14:26'),
(189, 1, '60699f933bca2', '82', 0, '2021-04-04 11:14:27'),
(193, 2, '6069a0ea857aa', '114', 0, '2021-04-04 11:20:10'),
(190, 2, '60699fd4a12d2', '49', 0, '2021-04-04 11:15:32'),
(191, 1, '60699fd59339d', '82', 0, '2021-04-04 11:15:33'),
(194, 1, '6069a0f11f6c1', '124', 0, '2021-04-04 11:20:17'),
(192, 2, '6069a039d2f41', '97', 0, '2021-04-04 11:17:13'),
(197, 2, '6069a16ed021b', '205', 0, '2021-04-04 11:22:22'),
(198, 1, '6069a176515ee', '215', 0, '2021-04-04 11:22:30'),
(200, 1, '6069d15254d8b', '', 0, '2021-04-04 14:46:42'),
(201, 2, '6069d1e6f3191', '49', 0, '2021-04-04 14:49:11'),
(202, 1, '6069d1ea14381', '82', 0, '2021-04-04 14:49:14'),
(205, 2, '6069d46a136c8', '293', 0, '2021-04-04 14:59:54'),
(203, 2, '6069d3d03d485', '159', 0, '2021-04-04 14:57:20'),
(204, 2, '6069d42c78b02', '276', 0, '2021-04-04 14:58:52'),
(206, 2, '6069d47d0375b', '303', 0, '2021-04-04 15:00:13'),
(207, 1, '6069d9e49d382', '49', 0, '2021-04-04 15:23:16'),
(208, 2, '6069d9f4030cc', '82', 0, '2021-04-04 15:23:32'),
(226, 2, '6069de9f761d4', '324', 0, '2021-04-04 15:43:27'),
(209, 1, '6069da09426c4', '', 0, '2021-04-04 15:23:53'),
(210, 2, '6069da304d0e3', '49', 0, '2021-04-04 15:24:32'),
(211, 1, '6069da3285d00', '83', 0, '2021-04-04 15:24:34'),
(212, 2, '6069da60be7e4', '49', 0, '2021-04-04 15:25:20'),
(213, 1, '6069da6b88592', '82', 0, '2021-04-04 15:25:31'),
(222, 2, '6069ddd970377', '262', 0, '2021-04-04 15:40:09'),
(214, 2, '6069daa3cb3ae', '79', 0, '2021-04-04 15:26:27'),
(215, 1, '6069daa836076', '88', 0, '2021-04-04 15:26:32'),
(216, 1, '6069dac527606', '49', 0, '2021-04-04 15:27:01'),
(217, 2, '6069dac619d50', '82', 0, '2021-04-04 15:27:02'),
(218, 2, '6069db1d0daae', '49', 0, '2021-04-04 15:28:29'),
(224, 2, '6069de751c7fb', '310', 0, '2021-04-04 15:42:45'),
(219, 1, '6069db23ce747', '82', 0, '2021-04-04 15:28:35'),
(221, 1, '6069dce7e5042', '226', 0, '2021-04-04 15:36:07'),
(220, 1, '6069dcc36ec62', '215', 0, '2021-04-04 15:35:31'),
(225, 2, '6069de947c973', '317', 0, '2021-04-04 15:43:16'),
(223, 2, '6069dde85b72e', '269', 0, '2021-04-04 15:40:24'),
(227, 2, '6069defe4d9a4', '337', 0, '2021-04-04 15:45:02'),
(228, 2, '6069dfa0d7e53', '372', 0, '2021-04-04 15:47:44'),
(229, 2, '6069dfd810e90', '409', 0, '2021-04-04 15:48:40'),
(230, 1, '6069e54b3bf95', '490', 0, '2021-04-04 16:11:55'),
(232, 1, '6069e5d27e0e7', '513', 0, '2021-04-04 16:14:10'),
(231, 1, '6069e551643c2', '497', 0, '2021-04-04 16:12:01'),
(233, 1, '6069e6ab002f4', '567', 0, '2021-04-04 16:17:47'),
(234, 1, '6069e8ad0c47f', '641', 0, '2021-04-04 16:26:21'),
(235, 2, '6069e989c2a04', '49', 0, '2021-04-04 16:30:01'),
(240, 2, '6069eae89e3b7', '118', 0, '2021-04-04 16:35:52'),
(236, 1, '6069e9bd5c0b3', '82', 0, '2021-04-04 16:30:53'),
(237, 1, '6069e9f91a67a', '49', 0, '2021-04-04 16:31:53'),
(241, 2, '6069eb015d838', '125', 0, '2021-04-04 16:36:17'),
(238, 2, '6069e9fc9deb1', '82', 0, '2021-04-04 16:31:56'),
(242, 2, '6069eb3404aca', '138', 0, '2021-04-04 16:37:08'),
(239, 1, '6069eacbb963a', '102', 0, '2021-04-04 16:35:23'),
(243, 2, '6069eb5f9eb65', '178', 0, '2021-04-04 16:37:51'),
(244, 2, '6069eb9d442c7', '187', 0, '2021-04-04 16:38:53'),
(245, 2, '6069ebb1adc52', '194', 0, '2021-04-04 16:39:13'),
(246, 1, '6069ebd3c662e', '208', 0, '2021-04-04 16:39:47'),
(250, 2, '6069ecb050bc4', '290', 0, '2021-04-04 16:43:28'),
(247, 2, '6069ec320e9ed', '220', 0, '2021-04-04 16:41:22'),
(248, 1, '6069ec350acc1', '227', 0, '2021-04-04 16:41:25'),
(249, 1, '6069ecad03afc', '283', 0, '2021-04-04 16:43:25'),
(252, 1, '6069f09d62f62', '432', 0, '2021-04-04 17:00:13'),
(251, 2, '6069f09b75d64', '425', 0, '2021-04-04 17:00:11'),
(255, 1, '6069f25e0fdf2', '511', 0, '2021-04-04 17:07:42'),
(253, 2, '6069f0ff8b544', '487', 0, '2021-04-04 17:01:51'),
(254, 2, '6069f129491b1', '494', 0, '2021-04-04 17:02:33'),
(259, 1, '6069f3c6710c0', '49', 0, '2021-04-04 17:13:42'),
(256, 2, '6069f26a11210', '520', 0, '2021-04-04 17:07:54'),
(262, 1, '6069f3dcaeffb', '103', 0, '2021-04-04 17:14:04'),
(257, 1, '6069f2b51746e', '535', 0, '2021-04-04 17:09:09'),
(258, 2, '6069f2b5f106c', '542', 0, '2021-04-04 17:09:09'),
(260, 2, '6069f3c8467f6', '83', 0, '2021-04-04 17:13:44'),
(263, 1, '6069f43be4b22', '49', 0, '2021-04-04 17:15:39'),
(261, 1, '6069f3d0f291a', '94', 0, '2021-04-04 17:13:52'),
(269, 1, '6069f4ae16b54', '103', 0, '2021-04-04 17:17:34'),
(264, 2, '6069f43e21301', '83', 0, '2021-04-04 17:15:42'),
(266, 2, '6069f4a0273d4', '49', 0, '2021-04-04 17:17:20'),
(265, 2, '6069f453f2a03', '94', 0, '2021-04-04 17:16:03'),
(270, 1, '6069f504ba68f', '49', 0, '2021-04-04 17:19:00'),
(267, 1, '6069f4a254503', '83', 0, '2021-04-04 17:17:22'),
(291, 2, '6069fe231e01d', '330', 0, '2021-04-04 17:57:55'),
(268, 2, '6069f4a5eed1c', '94', 0, '2021-04-04 17:17:25'),
(271, 2, '6069f506cbf21', '83', 0, '2021-04-04 17:19:02'),
(272, 1, '6069f52f3c7d5', '94', 0, '2021-04-04 17:19:43'),
(273, 1, '6069f55c39d79', '49', 0, '2021-04-04 17:20:28'),
(274, 2, '6069f55d87858', '83', 0, '2021-04-04 17:20:29'),
(275, 1, '6069f5643fb3c', '94', 0, '2021-04-04 17:20:36'),
(276, 1, '6069f5913117b', '49', 0, '2021-04-04 17:21:21'),
(288, 2, '6069f8bbdde1e', '175', 0, '2021-04-04 17:34:51'),
(277, 2, '6069f593594af', '83', 0, '2021-04-04 17:21:23'),
(281, 1, '6069f5c95e599', '49', 0, '2021-04-04 17:22:17'),
(278, 1, '6069f5aca5f0d', '49', 0, '2021-04-04 17:21:48'),
(279, 2, '6069f5ae93452', '83', 0, '2021-04-04 17:21:50'),
(280, 1, '6069f5b148b10', '94', 0, '2021-04-04 17:21:53'),
(289, 1, '6069f8be2ee27', '184', 0, '2021-04-04 17:34:54'),
(282, 2, '6069f5cabd1af', '83', 0, '2021-04-04 17:22:18'),
(283, 2, '6069f5d2e5aae', '94', 0, '2021-04-04 17:22:26'),
(284, 2, '6069f5d483425', '103', 0, '2021-04-04 17:22:28'),
(287, 2, '6069f8832609b', '166', 0, '2021-04-04 17:33:55'),
(285, 1, '6069f7765385c', '142', 0, '2021-04-04 17:29:26'),
(286, 1, '6069f7854b714', '151', 0, '2021-04-04 17:29:41'),
(290, 1, '6069fe219d5d5', '321', 0, '2021-04-04 17:57:53'),
(295, 1, '6069fec3e635f', '117', 0, '2021-04-04 18:00:35'),
(292, 1, '6069fe3ad3688', '49', 0, '2021-04-04 17:58:18'),
(293, 2, '6069fe3c67c3b', '83', 0, '2021-04-04 17:58:20'),
(296, 1, '6069fefd6d2ef', '49', 0, '2021-04-04 18:01:33'),
(294, 1, '6069fea4d7c7a', '101', 0, '2021-04-04 18:00:04'),
(297, 1, '6069ff84302d6', '49', 0, '2021-04-04 18:03:48'),
(299, 1, '606a009b1e6e4', '109', 0, '2021-04-04 18:08:27'),
(298, 1, '606a0090c6a37', '101', 0, '2021-04-04 18:08:16'),
(300, 1, '606a022e1acc8', '172', 0, '2021-04-04 18:15:10'),
(301, 1, '606a02771c036', '180', 0, '2021-04-04 18:16:23'),
(302, 1, '606a0295d3a1c', '188', 0, '2021-04-04 18:16:53'),
(303, 1, '606a02d834059', '196', 0, '2021-04-04 18:18:00'),
(304, 1, '606a02fcbb534', '204', 0, '2021-04-04 18:18:36'),
(305, 1, '606a03bbaa305', '237', 0, '2021-04-04 18:21:47'),
(306, 1, '606a03d1807c6', '245', 0, '2021-04-04 18:22:09'),
(307, 1, '606a03e287a0b', '253', 0, '2021-04-04 18:22:26'),
(308, 1, '606a04e222600', '281', 0, '2021-04-04 18:26:42'),
(309, 1, '606a050243beb', '318', 0, '2021-04-04 18:27:14'),
(310, 1, '606a053e4fae5', '338', 0, '2021-04-04 18:28:14'),
(311, 1, '606a054dadd49', '346', 0, '2021-04-04 18:28:29'),
(312, 1, '606a055e25c7b', '354', 0, '2021-04-04 18:28:46'),
(313, 1, '606a056a148f7', '362', 0, '2021-04-04 18:28:58'),
(314, 1, '606a0c1d90e57', '402', 0, '2021-04-04 18:57:33'),
(315, 1, '606a0c243e7c5', '410', 0, '2021-04-04 18:57:40'),
(317, 1, '606a0c34db272', '429', 0, '2021-04-04 18:57:56'),
(316, 1, '606a0c31c3db3', '421', 0, '2021-04-04 18:57:53'),
(318, 1, '606a0c3977403', '437', 0, '2021-04-04 18:58:01'),
(319, 1, '606a0c70691d0', '445', 0, '2021-04-04 18:58:56'),
(320, 1, '606a0c9b2d226', '456', 0, '2021-04-04 18:59:39'),
(321, 1, '606a0c9e5f8eb', '464', 0, '2021-04-04 18:59:42'),
(322, 1, '606a0d28c0d68', '475', 0, '2021-04-04 19:02:00'),
(323, 1, '606a0d2b0d198', '483', 0, '2021-04-04 19:02:03'),
(324, 1, '606a0d2df312f', '491', 0, '2021-04-04 19:02:05'),
(325, 1, '606a0d328d5af', '499', 0, '2021-04-04 19:02:10'),
(326, 1, '606a0d3673175', '507', 0, '2021-04-04 19:02:14'),
(327, 1, '606a0d398982e', '515', 0, '2021-04-04 19:02:17'),
(328, 1, '606a0d4b97157', '523', 0, '2021-04-04 19:02:35'),
(329, 1, '606a0e5d47686', '557', 0, '2021-04-04 19:07:09'),
(330, 1, '606a0f3f70f88', '594', 0, '2021-04-04 19:10:55'),
(331, 1, '606a0f4bc417e', '602', 0, '2021-04-04 19:11:07'),
(332, 1, '606a0f5a62558', '610', 0, '2021-04-04 19:11:22'),
(333, 1, '606a0f5c7202c', '618', 0, '2021-04-04 19:11:24'),
(334, 1, '606a0f78335ca', '629', 0, '2021-04-04 19:11:52'),
(335, 1, '606a0f7d46cc7', '', 0, '2021-04-04 19:11:57'),
(336, 1, '606a0fbace7f0', '', 0, '2021-04-04 19:12:58'),
(337, 1, '606a0fc65565a', '', 0, '2021-04-04 19:13:10'),
(338, 1, '606a0fcf53d82', '', 0, '2021-04-04 19:13:19'),
(339, 1, '606a0ff398589', '', 0, '2021-04-04 19:13:55'),
(340, 1, '606a0ffbc88b1', '', 0, '2021-04-04 19:14:03'),
(341, 1, '606a1023e4fb3', '', 0, '2021-04-04 19:14:43'),
(342, 1, '606a10324d09a', '', 0, '2021-04-04 19:14:58'),
(343, 1, '606a1054ac0df', '', 0, '2021-04-04 19:15:32'),
(344, 1, '606b08b224a6d', '129', 0, '2021-04-05 12:55:14'),
(346, 1, '606b0a7e6a9bc', '201', 0, '2021-04-05 13:02:54'),
(345, 1, '606b0a6aaca1e', '190', 0, '2021-04-05 13:02:34'),
(347, 1, '606b0a8add480', '209', 0, '2021-04-05 13:03:06'),
(348, 1, '606b0a90ee7cb', '217', 0, '2021-04-05 13:03:12'),
(349, 1, '606b0ab292e37', '228', 0, '2021-04-05 13:03:46'),
(350, 2, '606b0c4932197', '310', 0, '2021-04-05 13:10:33'),
(351, 2, '606b0c59a22de', '322', 0, '2021-04-05 13:10:49'),
(354, 1, '606b0defc5436', '390', 0, '2021-04-05 13:17:35'),
(352, 1, '606b0c5f59eb5', '331', 0, '2021-04-05 13:10:55'),
(353, 1, '606b0dbf4a8da', '381', 0, '2021-04-05 13:16:47'),
(355, 1, '606b0dfd2bbc5', '', 0, '2021-04-05 13:17:49'),
(356, 1, '606b0dfd86a15', '399', 0, '2021-04-05 13:17:49'),
(357, 1, '606b6fb319d43', '49', 0, '2021-04-05 20:14:43'),
(358, 2, '606b73e763a18', '232', 0, '2021-04-05 20:32:39'),
(359, 2, '606b7490b5330', '278', 0, '2021-04-05 20:35:28'),
(360, 2, '606b749ca2222', '288', 0, '2021-04-05 20:35:40'),
(361, 2, '606b75f1c5964', '339', 0, '2021-04-05 20:41:21'),
(363, 1, '606b77290838e', '599', 0, '2021-04-05 20:46:33'),
(362, 2, '606b7640dbada', '421', 0, '2021-04-05 20:42:40'),
(364, 1, '606b77b0adcfc', '703', 0, '2021-04-05 20:48:48'),
(365, 1, '606b780a2719c', '', 0, '2021-04-05 20:50:18'),
(366, 2, '606b782a32da5', '', 0, '2021-04-05 20:50:50'),
(367, 2, '6094207e21ac6', '', 0, '2021-05-06 16:59:42'),
(368, 2, '609420e16b94b', '', 0, '2021-05-06 17:01:21'),
(369, 2, '6094211d90a94', '49', 0, '2021-05-06 17:02:21'),
(370, 1, '6094227c6ee59', '123', 0, '2021-05-06 17:08:12'),
(371, 2, '6094260f81bbc', '270', 0, '2021-05-06 17:23:27'),
(372, 1, '6094262a71615', '283', 0, '2021-05-06 17:23:54'),
(374, 2, '6094264e06e3f', '306', 0, '2021-05-06 17:24:30'),
(373, 1, '60942639ddf3c', '292', 0, '2021-05-06 17:24:09'),
(378, 2, '6094285e222f0', '367', 0, '2021-05-06 17:33:18'),
(375, 1, '60942657e19b0', '315', 0, '2021-05-06 17:24:39'),
(376, 2, '6094265d95912', '324', 0, '2021-05-06 17:24:45'),
(377, 2, '609428523ef44', '351', 0, '2021-05-06 17:33:06'),
(379, 2, '609428647dfcb', '376', 0, '2021-05-06 17:33:24'),
(380, 2, '60942864b4144', '385', 0, '2021-05-06 17:33:24'),
(381, 2, '6094288823489', '394', 0, '2021-05-06 17:34:00'),
(382, 2, '6094288f7b0ac', '407', 0, '2021-05-06 17:34:07'),
(383, 2, '609428917b248', '416', 0, '2021-05-06 17:34:09'),
(384, 2, '609428b991371', '425', 0, '2021-05-06 17:34:49'),
(385, 2, '609428ccad71b', '439', 0, '2021-05-06 17:35:08'),
(386, 2, '6094292edd163', '457', 0, '2021-05-06 17:36:46'),
(387, 1, '60945cd943fa2', '', 0, '2021-05-06 21:17:13'),
(388, 1, '60945cfe51f37', '', 0, '2021-05-06 21:17:50'),
(389, 1, '60945db631403', '76', 0, '2021-05-06 21:20:54'),
(390, 2, '60945dd3ee65b', '86', 0, '2021-05-06 21:21:23'),
(391, 1, '60945dff1dcc8', '97', 0, '2021-05-06 21:22:07'),
(392, 2, '60945e160b090', '115', 0, '2021-05-06 21:22:30'),
(394, 1, '60945e29b76e0', '141', 0, '2021-05-06 21:22:49'),
(393, 2, '60945e2055954', '124', 0, '2021-05-06 21:22:40'),
(396, 1, '60945e39312df', '163', 0, '2021-05-06 21:23:05'),
(395, 1, '60945e3019983', '154', 0, '2021-05-06 21:22:56');

--
-- Dökümü yapılmış tablolar için indeksler
--

--
-- Tablo için indeksler `Groups`
--
ALTER TABLE `Groups`
  ADD PRIMARY KEY (`GID`);

--
-- Tablo için indeksler `GroupUsers`
--
ALTER TABLE `GroupUsers`
  ADD PRIMARY KEY (`GUID`);

--
-- Tablo için indeksler `Messages`
--
ALTER TABLE `Messages`
  ADD PRIMARY KEY (`MID`);

--
-- Tablo için indeksler `Seen`
--
ALTER TABLE `Seen`
  ADD PRIMARY KEY (`SID`);

--
-- Tablo için indeksler `Users`
--
ALTER TABLE `Users`
  ADD PRIMARY KEY (`UID`);

--
-- Tablo için indeksler `UserTokens`
--
ALTER TABLE `UserTokens`
  ADD PRIMARY KEY (`UTID`);

--
-- Dökümü yapılmış tablolar için AUTO_INCREMENT değeri
--

--
-- Tablo için AUTO_INCREMENT değeri `Groups`
--
ALTER TABLE `Groups`
  MODIFY `GID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- Tablo için AUTO_INCREMENT değeri `GroupUsers`
--
ALTER TABLE `GroupUsers`
  MODIFY `GUID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- Tablo için AUTO_INCREMENT değeri `Messages`
--
ALTER TABLE `Messages`
  MODIFY `MID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=132;

--
-- Tablo için AUTO_INCREMENT değeri `Seen`
--
ALTER TABLE `Seen`
  MODIFY `SID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- Tablo için AUTO_INCREMENT değeri `Users`
--
ALTER TABLE `Users`
  MODIFY `UID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- Tablo için AUTO_INCREMENT değeri `UserTokens`
--
ALTER TABLE `UserTokens`
  MODIFY `UTID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=397;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
