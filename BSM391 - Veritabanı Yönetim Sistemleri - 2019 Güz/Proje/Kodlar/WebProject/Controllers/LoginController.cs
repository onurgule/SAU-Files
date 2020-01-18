using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;
using WebProject.Models;

namespace WebProject.Controllers
{
    public class LoginController : Controller
    {
        // GET: Login
        dbEntities db = new dbEntities();
        [HttpGet]
        public ActionResult Index()
        {
            if (String.IsNullOrEmpty(HttpContext.User.Identity.Name))
            {
                FormsAuthentication.SignOut();
                return View();
            }
            return RedirectToAction("Home","Home");
        }
        [HttpPost]
        public ActionResult Index(Login lg)
        {
            if (ModelState.IsValid)
            {
                //LOGIN PROSEDURE KULLANILDI
                var kullanici = db.GirisYap(lg.Email, lg.Password).ToList();
                if (kullanici.Count() > 0)
                {
                    FormsAuthentication.SetAuthCookie(kullanici.FirstOrDefault().UID.ToString(), true);
                    return RedirectToAction("Home", "Home");
                }

                else
                {
                    ModelState.AddModelError("", "EMail veya şifre hatalı!");
                }
            }
            return View(lg);
        }
        [HttpGet]
        public ActionResult Register()
        {
            var sehirler = db.Iller.ToList();
            ViewBag.sehirler = sehirler;
            
            if (String.IsNullOrEmpty(HttpContext.User.Identity.Name))
            {
                FormsAuthentication.SignOut();
                return View();
            }
            return Redirect("/Home/Home");
        }
        [HttpPost]
        public ActionResult Register(Login lg)
        {
            if (ModelState.IsValid)
            {

                var kullanici = db.Users.Where(x => x.Email == lg.Email);
                if (kullanici.Count() == 0)
                {
                    //BURADA Stored Procedure Kullanılacak... HAZIR.
                    db.KayitOl(lg.FirstName, lg.LastName, lg.Email, lg.Password, lg.Sehir);
                    db.SaveChanges();
                    //FormsAuthentication.SetAuthCookie(kullanici.FirstOrDefault().UID.ToString(), true);
                    return RedirectToAction("Index", "Login");
                }

                else
                {
                    ModelState.AddModelError("", "EMail bulunmakta!");
                }
            }
            return View(lg);
        }
        public ActionResult ChangeLanguage(string lang)
        {
            new LanguageManager().SetLanguage(lang);
            return RedirectToAction("Index", "Login");
        }
        [HttpGet]
        public ActionResult Logout()
        {
            FormsAuthentication.SignOut();
            return Redirect("/Home/Index");
        }
    }
}