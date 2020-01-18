--
-- PostgreSQL database dump
--

-- Dumped from database version 11.5
-- Dumped by pg_dump version 12rc1

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: G171210021; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE "G171210021" WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'Turkish_Turkey.1254' LC_CTYPE = 'Turkish_Turkey.1254';


ALTER DATABASE "G171210021" OWNER TO postgres;

--\connect "G171210021" -- bazen hata verebiliyor

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: Post; Type: SCHEMA; Schema: -; Owner: postgres
--

CREATE SCHEMA "Post";


ALTER SCHEMA "Post" OWNER TO postgres;

SET default_tablespace = '';

--
-- Name: Answers; Type: TABLE; Schema: Post; Owner: postgres
--

CREATE TABLE "Post"."Answers" (
    "PID" integer NOT NULL,
    "AID" integer NOT NULL,
    "QID" integer NOT NULL,
    "IsSelected" boolean DEFAULT false
);


ALTER TABLE "Post"."Answers" OWNER TO postgres;

--
-- Name: Answers_AID_seq; Type: SEQUENCE; Schema: Post; Owner: postgres
--

ALTER TABLE "Post"."Answers" ALTER COLUMN "AID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME "Post"."Answers_AID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: Posts; Type: TABLE; Schema: Post; Owner: postgres
--

CREATE TABLE "Post"."Posts" (
    "PID" integer NOT NULL,
    "Description" text,
    "PostByUID" integer NOT NULL,
    "PostDate" date
);


ALTER TABLE "Post"."Posts" OWNER TO postgres;

--
-- Name: Posts_PID_seq; Type: SEQUENCE; Schema: Post; Owner: postgres
--

ALTER TABLE "Post"."Posts" ALTER COLUMN "PID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME "Post"."Posts_PID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: Questions; Type: TABLE; Schema: Post; Owner: postgres
--

CREATE TABLE "Post"."Questions" (
    "PID" integer NOT NULL,
    "QID" integer NOT NULL,
    "Title" text
);


ALTER TABLE "Post"."Questions" OWNER TO postgres;

--
-- Name: Questions_QID_seq; Type: SEQUENCE; Schema: Post; Owner: postgres
--

ALTER TABLE "Post"."Questions" ALTER COLUMN "QID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME "Post"."Questions_QID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: Badges; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Badges" (
    "BID" integer NOT NULL,
    "BadgeName" text,
    "BadgeDesc" text
);


ALTER TABLE public."Badges" OWNER TO postgres;

--
-- Name: Badges_BID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Badges" ALTER COLUMN "BID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Badges_BID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: Comments; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Comments" (
    "ComID" integer NOT NULL,
    "CommentedBy" integer NOT NULL,
    "PostID" integer NOT NULL,
    "Comment" text NOT NULL,
    "CommentDate" date NOT NULL
);


ALTER TABLE public."Comments" OWNER TO postgres;

--
-- Name: Comments_ComID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Comments" ALTER COLUMN "ComID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Comments_ComID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: EmailVerification; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."EmailVerification" (
    "EVID" integer NOT NULL,
    "UID" integer NOT NULL,
    "Token" text NOT NULL,
    "Valid" boolean,
    "Date" date
);


ALTER TABLE public."EmailVerification" OWNER TO postgres;

--
-- Name: EmailVerification_EVID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."EmailVerification" ALTER COLUMN "EVID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."EmailVerification_EVID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: Favorites; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Favorites" (
    "FavID" integer NOT NULL,
    "UID" integer NOT NULL,
    "QID" integer NOT NULL
);


ALTER TABLE public."Favorites" OWNER TO postgres;

--
-- Name: Favorites_FavID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Favorites" ALTER COLUMN "FavID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Favorites_FavID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: Messages; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Messages" (
    "MID" integer NOT NULL,
    "FromUID" integer NOT NULL,
    "ToUID" integer NOT NULL,
    "Message" text,
    "MessageDate" date NOT NULL
);


ALTER TABLE public."Messages" OWNER TO postgres;

--
-- Name: Messages_MID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Messages" ALTER COLUMN "MID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Messages_MID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: Pictures; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Pictures" (
    url text,
    "UploadedDate" date NOT NULL,
    "UploadedBy" integer NOT NULL,
    "PictureID" integer NOT NULL
);


ALTER TABLE public."Pictures" OWNER TO postgres;

--
-- Name: Pictures_PictureID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Pictures" ALTER COLUMN "PictureID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Pictures_PictureID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: Pictures_UploadedBy_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Pictures_UploadedBy_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Pictures_UploadedBy_seq" OWNER TO postgres;

--
-- Name: Pictures_UploadedBy_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Pictures_UploadedBy_seq" OWNED BY public."Pictures"."UploadedBy";


--
-- Name: Preferences; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Preferences" (
    "PrID" integer NOT NULL,
    "UID" integer NOT NULL,
    "KeyShortcuts" boolean,
    "DisableTopNav" boolean,
    "HideLeftNav" boolean,
    "HideHotNewQues" boolean
);


ALTER TABLE public."Preferences" OWNER TO postgres;

--
-- Name: Preferences_PrID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Preferences" ALTER COLUMN "PrID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Preferences_PrID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: Privileges; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Privileges" (
    "PriID" integer NOT NULL,
    "PriName" text NOT NULL,
    "PriDesc" text,
    "Reputation" integer NOT NULL
);


ALTER TABLE public."Privileges" OWNER TO postgres;

--
-- Name: Privileges_PriID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Privileges" ALTER COLUMN "PriID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Privileges_PriID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: ProfileDetails; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."ProfileDetails" (
    "PID" integer NOT NULL,
    "UID" integer NOT NULL,
    "AboutMe" text,
    "Location" text,
    "DisplayName" text,
    "FullName" text,
    "Website" text,
    "Twitter" text,
    "Github" text,
    "PictureID" integer
);


ALTER TABLE public."ProfileDetails" OWNER TO postgres;

--
-- Name: ProfileDetails_PID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."ProfileDetails" ALTER COLUMN "PID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."ProfileDetails_PID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: QuestionTags; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."QuestionTags" (
    "QTID" integer NOT NULL,
    "TID" integer NOT NULL,
    "QID" integer NOT NULL
);


ALTER TABLE public."QuestionTags" OWNER TO postgres;

--
-- Name: QuestionTags_QTID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."QuestionTags" ALTER COLUMN "QTID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."QuestionTags_QTID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: Reputations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Reputations" (
    "RepID" integer NOT NULL,
    "RepFrom" integer NOT NULL,
    "PostID" integer NOT NULL,
    "Value" integer NOT NULL
);


ALTER TABLE public."Reputations" OWNER TO postgres;

--
-- Name: Reputations_RepID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Reputations" ALTER COLUMN "RepID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Reputations_RepID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: Tags; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Tags" (
    "TID" integer NOT NULL,
    "TagName" text NOT NULL,
    "TagDesc" text
);


ALTER TABLE public."Tags" OWNER TO postgres;

--
-- Name: Tags_TID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Tags" ALTER COLUMN "TID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Tags_TID_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: Users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Users" (
    "UID" integer NOT NULL,
    "Email" text NOT NULL,
    "Password" text NOT NULL,
    "AdOpt" boolean,
    "CreatedDate" date NOT NULL,
    CONSTRAINT "SifreMinKarakterUzunlugu" CHECK ((length("Password") > 5))
);


ALTER TABLE public."Users" OWNER TO postgres;

--
-- Name: Users_UID_seq1; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Users" ALTER COLUMN "UID" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Users_UID_seq1"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: Pictures UploadedBy; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Pictures" ALTER COLUMN "UploadedBy" SET DEFAULT nextval('public."Pictures_UploadedBy_seq"'::regclass);


--
-- Data for Name: Answers; Type: TABLE DATA; Schema: Post; Owner: postgres
--

INSERT INTO "Post"."Answers" OVERRIDING SYSTEM VALUE VALUES (4, 1, 4, true);
INSERT INTO "Post"."Answers" OVERRIDING SYSTEM VALUE VALUES (6, 2, 5, true);
INSERT INTO "Post"."Answers" OVERRIDING SYSTEM VALUE VALUES (7, 3, 5, false);


--
-- Data for Name: Posts; Type: TABLE DATA; Schema: Post; Owner: postgres
--

INSERT INTO "Post"."Posts" OVERRIDING SYSTEM VALUE VALUES (1, 'Ubuntu''da dosyaları nasıl listeleyebilirim acaba?', 2, '2019-11-26');
INSERT INTO "Post"."Posts" OVERRIDING SYSTEM VALUE VALUES (4, 'Dosyaları listelemek için >ls komutunu kullanabilirsin.', 1, '2019-11-26');
INSERT INTO "Post"."Posts" OVERRIDING SYSTEM VALUE VALUES (5, '64 bit ubuntu sistemi var mı?', 4, '2019-11-26');
INSERT INTO "Post"."Posts" OVERRIDING SYSTEM VALUE VALUES (6, 'Elbette, ubuntunun sitesinden indirebilirsiniz.', 1, '2019-11-26');
INSERT INTO "Post"."Posts" OVERRIDING SYSTEM VALUE VALUES (7, 'Ayrıca Pardus da kurabilirsiniz, Türkiye destekli bir işletim sistemi.', 2, '2019-11-26');


--
-- Data for Name: Questions; Type: TABLE DATA; Schema: Post; Owner: postgres
--

INSERT INTO "Post"."Questions" OVERRIDING SYSTEM VALUE VALUES (1, 4, 'Ubuntu Dosya Listeleme');
INSERT INTO "Post"."Questions" OVERRIDING SYSTEM VALUE VALUES (5, 5, '64Bit Ubuntu');


--
-- Data for Name: Badges; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Badges" OVERRIDING SYSTEM VALUE VALUES (1, 'Welcome', 'Hosgeldiniz');
INSERT INTO public."Badges" OVERRIDING SYSTEM VALUE VALUES (2, 'First Question', 'Ilk sorusunu sordu!');
INSERT INTO public."Badges" OVERRIDING SYSTEM VALUE VALUES (3, 'First Answer', 'Ilk cevabını verdi!');


--
-- Data for Name: Comments; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Comments" OVERRIDING SYSTEM VALUE VALUES (1, 1, 7, 'Ubuntu kadar stabil değil.', '2019-11-26');
INSERT INTO public."Comments" OVERRIDING SYSTEM VALUE VALUES (2, 4, 1, 'Commandline''dan mı istiyorsunuz?', '2019-11-26');


--
-- Data for Name: EmailVerification; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."EmailVerification" OVERRIDING SYSTEM VALUE VALUES (1, 1, '3r2fjh2gkwbfd', true, '2019-11-25');
INSERT INTO public."EmailVerification" OVERRIDING SYSTEM VALUE VALUES (2, 2, '7f4h7g5hgfjbb', false, '2019-11-26');
INSERT INTO public."EmailVerification" OVERRIDING SYSTEM VALUE VALUES (3, 2, 'tt7fdg9fdfgfe', true, '2019-11-26');
INSERT INTO public."EmailVerification" OVERRIDING SYSTEM VALUE VALUES (4, 4, 'h5h5dgg5g5gg', true, '2019-11-26');


--
-- Data for Name: Favorites; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Favorites" OVERRIDING SYSTEM VALUE VALUES (5, 1, 4);
INSERT INTO public."Favorites" OVERRIDING SYSTEM VALUE VALUES (6, 4, 4);
INSERT INTO public."Favorites" OVERRIDING SYSTEM VALUE VALUES (7, 2, 4);
INSERT INTO public."Favorites" OVERRIDING SYSTEM VALUE VALUES (8, 1, 5);


--
-- Data for Name: Messages; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Messages" OVERRIDING SYSTEM VALUE VALUES (1, 1, 4, 'Koray merhaba, ubuntu''nun hangi sürümünü kullanıyorsun?', '2019-11-25');
INSERT INTO public."Messages" OVERRIDING SYSTEM VALUE VALUES (2, 4, 1, 'Son sürümünü 19.10 kullanıyorum.', '2019-11-26');
INSERT INTO public."Messages" OVERRIDING SYSTEM VALUE VALUES (3, 2, 1, 'Merhaba, ubuntu tavsiye ediyor musunuz?', '2019-11-26');
INSERT INTO public."Messages" OVERRIDING SYSTEM VALUE VALUES (4, 1, 2, 'Tabii, gayet stabil bir işletim sistemi.', '2019-11-26');


--
-- Data for Name: Pictures; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Pictures" OVERRIDING SYSTEM VALUE VALUES ('profile1.png', '2019-11-26', 1, 1);
INSERT INTO public."Pictures" OVERRIDING SYSTEM VALUE VALUES ('Whatsapp_04423.jpg', '2019-11-26', 4, 2);


--
-- Data for Name: Preferences; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Preferences" OVERRIDING SYSTEM VALUE VALUES (1, 1, true, true, true, true);
INSERT INTO public."Preferences" OVERRIDING SYSTEM VALUE VALUES (2, 2, true, false, true, true);
INSERT INTO public."Preferences" OVERRIDING SYSTEM VALUE VALUES (3, 4, true, false, false, false);


--
-- Data for Name: Privileges; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Privileges" OVERRIDING SYSTEM VALUE VALUES (1, 'Moderator', 'Can delete posts, edit posts.', 1500);
INSERT INTO public."Privileges" OVERRIDING SYSTEM VALUE VALUES (2, 'Editor', 'Can edit posts.', 1000);
INSERT INTO public."Privileges" OVERRIDING SYSTEM VALUE VALUES (3, 'Faster', 'Can downvote.', 100);


--
-- Data for Name: ProfileDetails; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."ProfileDetails" OVERRIDING SYSTEM VALUE VALUES (1, 1, 'Onur Osman Güle,
Sakarya Üniversitesi Bilgisayar Mühendisliği 3. Sınıf öğrencisiyim.', 'Sakarya', NULL, NULL, 'https://onurgule.com.tr', NULL, NULL, 1);
INSERT INTO public."ProfileDetails" OVERRIDING SYSTEM VALUE VALUES (2, 2, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO public."ProfileDetails" OVERRIDING SYSTEM VALUE VALUES (3, 4, 'Ben Koray, Ankara''da oturuyorum.', 'Ankara', NULL, NULL, NULL, NULL, NULL, 2);


--
-- Data for Name: QuestionTags; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."QuestionTags" OVERRIDING SYSTEM VALUE VALUES (4, 1, 4);
INSERT INTO public."QuestionTags" OVERRIDING SYSTEM VALUE VALUES (5, 2, 4);
INSERT INTO public."QuestionTags" OVERRIDING SYSTEM VALUE VALUES (6, 2, 5);


--
-- Data for Name: Reputations; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Reputations" OVERRIDING SYSTEM VALUE VALUES (1, 1, 7, 5);
INSERT INTO public."Reputations" OVERRIDING SYSTEM VALUE VALUES (2, 4, 6, 1);
INSERT INTO public."Reputations" OVERRIDING SYSTEM VALUE VALUES (3, 4, 4, 1);
INSERT INTO public."Reputations" OVERRIDING SYSTEM VALUE VALUES (4, 2, 4, 1);


--
-- Data for Name: Tags; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Tags" OVERRIDING SYSTEM VALUE VALUES (1, 'Ubuntu', 'Posts about Ubuntu.');
INSERT INTO public."Tags" OVERRIDING SYSTEM VALUE VALUES (2, 'OS', 'Posts about Operation Systems.');
INSERT INTO public."Tags" OVERRIDING SYSTEM VALUE VALUES (3, 'Coding', 'Posts about coding.');


--
-- Data for Name: Users; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Users" OVERRIDING SYSTEM VALUE VALUES (1, 'onur.gule@ogr.sakarya.edu.tr', '112233', true, '2019-11-26');
INSERT INTO public."Users" OVERRIDING SYSTEM VALUE VALUES (2, 'ahmet@gmail.com', '123123', false, '2019-11-27');
INSERT INTO public."Users" OVERRIDING SYSTEM VALUE VALUES (4, 'koray@gmail.com', '66778899', true, '2019-11-29');


--
-- Name: Answers_AID_seq; Type: SEQUENCE SET; Schema: Post; Owner: postgres
--

SELECT pg_catalog.setval('"Post"."Answers_AID_seq"', 3, true);


--
-- Name: Posts_PID_seq; Type: SEQUENCE SET; Schema: Post; Owner: postgres
--

SELECT pg_catalog.setval('"Post"."Posts_PID_seq"', 7, true);


--
-- Name: Questions_QID_seq; Type: SEQUENCE SET; Schema: Post; Owner: postgres
--

SELECT pg_catalog.setval('"Post"."Questions_QID_seq"', 5, true);


--
-- Name: Badges_BID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Badges_BID_seq"', 3, true);


--
-- Name: Comments_ComID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Comments_ComID_seq"', 2, true);


--
-- Name: EmailVerification_EVID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."EmailVerification_EVID_seq"', 4, true);


--
-- Name: Favorites_FavID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Favorites_FavID_seq"', 8, true);


--
-- Name: Messages_MID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Messages_MID_seq"', 4, true);


--
-- Name: Pictures_PictureID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Pictures_PictureID_seq"', 2, true);


--
-- Name: Pictures_UploadedBy_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Pictures_UploadedBy_seq"', 1, false);


--
-- Name: Preferences_PrID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Preferences_PrID_seq"', 3, true);


--
-- Name: Privileges_PriID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Privileges_PriID_seq"', 3, true);


--
-- Name: ProfileDetails_PID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ProfileDetails_PID_seq"', 3, true);


--
-- Name: QuestionTags_QTID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."QuestionTags_QTID_seq"', 6, true);


--
-- Name: Reputations_RepID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Reputations_RepID_seq"', 4, true);


--
-- Name: Tags_TID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Tags_TID_seq"', 3, true);


--
-- Name: Users_UID_seq1; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Users_UID_seq1"', 4, true);


--
-- Name: Answers Answers_pkey; Type: CONSTRAINT; Schema: Post; Owner: postgres
--

ALTER TABLE ONLY "Post"."Answers"
    ADD CONSTRAINT "Answers_pkey" PRIMARY KEY ("PID", "AID");


--
-- Name: Posts Posts_pkey; Type: CONSTRAINT; Schema: Post; Owner: postgres
--

ALTER TABLE ONLY "Post"."Posts"
    ADD CONSTRAINT "Posts_pkey" PRIMARY KEY ("PID");


--
-- Name: Questions Questions_QID_QID1_key; Type: CONSTRAINT; Schema: Post; Owner: postgres
--

ALTER TABLE ONLY "Post"."Questions"
    ADD CONSTRAINT "Questions_QID_QID1_key" UNIQUE ("QID") INCLUDE ("QID");


--
-- Name: Questions Questions_pkey; Type: CONSTRAINT; Schema: Post; Owner: postgres
--

ALTER TABLE ONLY "Post"."Questions"
    ADD CONSTRAINT "Questions_pkey" PRIMARY KEY ("PID", "QID");


--
-- Name: Badges Badges_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Badges"
    ADD CONSTRAINT "Badges_pkey" PRIMARY KEY ("BID");


--
-- Name: Comments Comments_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Comments"
    ADD CONSTRAINT "Comments_pkey" PRIMARY KEY ("ComID");


--
-- Name: Users EmailKontrolu; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Users"
    ADD CONSTRAINT "EmailKontrolu" UNIQUE ("Email") INCLUDE ("Email");


--
-- Name: EmailVerification EmailVerification_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."EmailVerification"
    ADD CONSTRAINT "EmailVerification_pkey" PRIMARY KEY ("EVID");


--
-- Name: Favorites Favorites_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Favorites"
    ADD CONSTRAINT "Favorites_pkey" PRIMARY KEY ("FavID");


--
-- Name: Messages Messages_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Messages"
    ADD CONSTRAINT "Messages_pkey" PRIMARY KEY ("MID");


--
-- Name: Pictures Pictures_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Pictures"
    ADD CONSTRAINT "Pictures_pkey" PRIMARY KEY ("PictureID");


--
-- Name: Preferences Preferences_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Preferences"
    ADD CONSTRAINT "Preferences_pkey" PRIMARY KEY ("PrID", "UID");


--
-- Name: Privileges Privileges_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Privileges"
    ADD CONSTRAINT "Privileges_pkey" PRIMARY KEY ("PriID");


--
-- Name: ProfileDetails ProfileDetails_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."ProfileDetails"
    ADD CONSTRAINT "ProfileDetails_pkey" PRIMARY KEY ("PID");


--
-- Name: QuestionTags QuestionTags_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."QuestionTags"
    ADD CONSTRAINT "QuestionTags_pkey" PRIMARY KEY ("QTID");


--
-- Name: Reputations Reputations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Reputations"
    ADD CONSTRAINT "Reputations_pkey" PRIMARY KEY ("RepID");


--
-- Name: Tags Tags_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Tags"
    ADD CONSTRAINT "Tags_pkey" PRIMARY KEY ("TID");


--
-- Name: Users Users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Users"
    ADD CONSTRAINT "Users_pkey" PRIMARY KEY ("UID");


--
-- Name: Preferences unique_Preferences_UID; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Preferences"
    ADD CONSTRAINT "unique_Preferences_UID" UNIQUE ("UID");


--
-- Name: ProfileDetails unique_ProfileDetails_UID; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."ProfileDetails"
    ADD CONSTRAINT "unique_ProfileDetails_UID" UNIQUE ("UID");


--
-- Name: Answers Answers_PID_fkey; Type: FK CONSTRAINT; Schema: Post; Owner: postgres
--

ALTER TABLE ONLY "Post"."Answers"
    ADD CONSTRAINT "Answers_PID_fkey" FOREIGN KEY ("PID") REFERENCES "Post"."Posts"("PID") ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Answers Answers_QID_fkey; Type: FK CONSTRAINT; Schema: Post; Owner: postgres
--

ALTER TABLE ONLY "Post"."Answers"
    ADD CONSTRAINT "Answers_QID_fkey" FOREIGN KEY ("QID") REFERENCES "Post"."Questions"("QID");


--
-- Name: Posts Posts_PostByUID_fkey; Type: FK CONSTRAINT; Schema: Post; Owner: postgres
--

ALTER TABLE ONLY "Post"."Posts"
    ADD CONSTRAINT "Posts_PostByUID_fkey" FOREIGN KEY ("PostByUID") REFERENCES public."Users"("UID");


--
-- Name: Questions Questions_PID_fkey; Type: FK CONSTRAINT; Schema: Post; Owner: postgres
--

ALTER TABLE ONLY "Post"."Questions"
    ADD CONSTRAINT "Questions_PID_fkey" FOREIGN KEY ("PID") REFERENCES "Post"."Posts"("PID") ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Comments Comments_CommentedBy_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Comments"
    ADD CONSTRAINT "Comments_CommentedBy_fkey" FOREIGN KEY ("CommentedBy") REFERENCES public."Users"("UID");


--
-- Name: Comments Comments_PostID_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Comments"
    ADD CONSTRAINT "Comments_PostID_fkey" FOREIGN KEY ("PostID") REFERENCES "Post"."Posts"("PID");


--
-- Name: EmailVerification EmailVerification_UID_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."EmailVerification"
    ADD CONSTRAINT "EmailVerification_UID_fkey" FOREIGN KEY ("UID") REFERENCES public."Users"("UID");


--
-- Name: Favorites Favorites_QID_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Favorites"
    ADD CONSTRAINT "Favorites_QID_fkey" FOREIGN KEY ("QID") REFERENCES "Post"."Questions"("QID");


--
-- Name: Favorites Favorites_UID_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Favorites"
    ADD CONSTRAINT "Favorites_UID_fkey" FOREIGN KEY ("UID") REFERENCES public."Users"("UID");


--
-- Name: Messages Messages_FromUID_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Messages"
    ADD CONSTRAINT "Messages_FromUID_fkey" FOREIGN KEY ("FromUID") REFERENCES public."Users"("UID");


--
-- Name: Messages Messages_ToUID_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Messages"
    ADD CONSTRAINT "Messages_ToUID_fkey" FOREIGN KEY ("ToUID") REFERENCES public."Users"("UID");


--
-- Name: Pictures Pictures_UploadedBy_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Pictures"
    ADD CONSTRAINT "Pictures_UploadedBy_fkey" FOREIGN KEY ("UploadedBy") REFERENCES public."Users"("UID");


--
-- Name: Preferences Preferences_UID_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Preferences"
    ADD CONSTRAINT "Preferences_UID_fkey" FOREIGN KEY ("UID") REFERENCES public."Users"("UID");


--
-- Name: ProfileDetails ProfileDetails_PictureID_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."ProfileDetails"
    ADD CONSTRAINT "ProfileDetails_PictureID_fkey" FOREIGN KEY ("PictureID") REFERENCES public."Pictures"("PictureID");


--
-- Name: ProfileDetails ProfileDetails_UID_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."ProfileDetails"
    ADD CONSTRAINT "ProfileDetails_UID_fkey" FOREIGN KEY ("UID") REFERENCES public."Users"("UID");


--
-- Name: QuestionTags QuestionTags_QID_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."QuestionTags"
    ADD CONSTRAINT "QuestionTags_QID_fkey" FOREIGN KEY ("QID") REFERENCES "Post"."Questions"("QID");


--
-- Name: QuestionTags QuestionTags_TID_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."QuestionTags"
    ADD CONSTRAINT "QuestionTags_TID_fkey" FOREIGN KEY ("TID") REFERENCES public."Tags"("TID");


--
-- Name: Reputations Reputations_PostID_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Reputations"
    ADD CONSTRAINT "Reputations_PostID_fkey" FOREIGN KEY ("PostID") REFERENCES "Post"."Posts"("PID");


--
-- Name: Reputations Reputations_RepFrom_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Reputations"
    ADD CONSTRAINT "Reputations_RepFrom_fkey" FOREIGN KEY ("RepFrom") REFERENCES public."Users"("UID");


--
-- Name: SCHEMA "Post"; Type: ACL; Schema: -; Owner: postgres
--

GRANT ALL ON SCHEMA "Post" TO PUBLIC;


--
-- PostgreSQL database dump complete
--

