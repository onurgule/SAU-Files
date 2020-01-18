using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;
using WebProject.Models;

namespace WebProject.Controllers
{

    
    public class HomeController : Controller
    {
        dbEntities db = new dbEntities();
        public ActionResult Kontrol()
        {
            string uid = User.Identity.Name;
            if (db.Users.Where(x => x.UID.ToString() == uid).Count() <= 0) return RedirectToAction("Logout", "Login");
            else return null;
        }
        public ActionResult Index()
        {
            return View();
        }
        // GET: Home
        [_SessionControl]
        public ActionResult Home()
        {
            if(Kontrol()!=null) return Kontrol();
            string uid = User.Identity.Name;
            HomeVar homeVar = new HomeVar();
            homeVar.user = db.Users.Where(x => x.UID.ToString() == uid).FirstOrDefault();
            homeVar.listBudgets = (from n in db.Budgets join c in db.Joins on n.BID equals c.BID orderby n.CreatedDate descending where c.UID == homeVar.user.UID select n).ToList();
            List<int> jbids = new List<int>();
            jbids = homeVar.listBudgets.Select(x => x.BID).ToList();
            //arkadaşlarının da actionlarını çek
            homeVar.listJoins = (from n in db.Joins join c in jbids on n.BID equals c orderby n.PID descending select n).ToList();
            //homeVar.listJoins = db.Joins.Where(x => homeVar.listBudgets.Where(k=>k.BID == x.BID).Any()).ToList();
            List<int> juids = new List<int>();
            juids = homeVar.listJoins.Select(x => x.UID).Distinct().ToList();
            homeVar.listActions = (from n in db.Action join c in juids on n.UID equals c orderby n.GID descending select n).Distinct().ToList();
            homeVar.listUsers = (from n in db.Users join c in juids on n.UID equals c orderby n.UID descending select n).Distinct().ToList();
            homeVar.listKurlar = db.Kurlar.ToList();
            homeVar.listParaBirimleri = db.ParaBirimleri.ToList();
            //homeVar.listActions = db.Action.Where(x => homeVar.listJoins.Any(k => k.UID == x.UID)).ToList();
            //homeVar.listActions = db.Action.Where(x => x.UID == homeVar.user.UID).ToList();
            if (Session["defBudget"]==null)
            Session.Add("defBudget", homeVar.listBudgets.OrderBy(x=>x.BID).FirstOrDefault());
            bool isAdmin = homeVar.user.Yetki==1?true:false;
            if (isAdmin) homeVar.isAdmin = true;
            else homeVar.isAdmin = false;
            return View(homeVar);
        }
        [HttpGet]
        public ActionResult ButceOlustur()
        {
            if (Kontrol() != null) return Kontrol();
            string uid = User.Identity.Name;
            HomeVar homeVar = new HomeVar();
            homeVar.user = db.Users.Where(x => x.UID.ToString() == uid).FirstOrDefault();
            homeVar.listBudgets = (from n in db.Budgets join c in db.Joins on n.BID equals c.BID orderby n.CreatedDate descending where c.UID == homeVar.user.UID select n).ToList();
            homeVar.listActions = db.Action.Where(x => x.UID == homeVar.user.UID).ToList();
            ViewBag.oncelikler = db.Oncelikler.ToList();
            ViewBag.budgetTypes = db.BudgetTypes.ToList();
            return View(homeVar);
        }
        [HttpPost]
        public ActionResult ButceOlustur(HomeVar hv)
        {
            if (Kontrol() != null) return Kontrol();
            //if (ModelState.IsValid)
            {

                //PROCEDURE KULLANILDI.
                string uid = User.Identity.Name;
                db.ButceOlustur(hv.budget.Name, hv.budget.BTID, hv.budget.Oncelik, Convert.ToInt32(uid));
                db.SaveChanges();
                return RedirectToAction("Home", "Home");
            }
            //return View(hv);
        }
        [_SessionControl]
        [HttpGet]
        public ActionResult ButceneEkle()
        {
            if (Kontrol() != null) return Kontrol();
            string uid = User.Identity.Name;
            HomeVar homeVar = new HomeVar();
            homeVar.user = db.Users.Where(x => x.UID.ToString() == uid).FirstOrDefault();
            homeVar.listBudgets = (from n in db.Budgets join c in db.Joins on n.BID equals c.BID orderby n.CreatedDate descending where c.UID == homeVar.user.UID select n).ToList();
            homeVar.listActions = db.Action.Where(x => x.UID == homeVar.user.UID).ToList();
            return View(homeVar);
        }
        [_SessionControl]
        [HttpPost]
        public ActionResult ButceneEkle(HomeVar hov)
        {
            if (Kontrol() != null) return Kontrol();
            string uid = User.Identity.Name;
            Models.Action ac = new Models.Action();
            ac.UID = Convert.ToInt32(uid);
            ac.BID = hov.actionn.BID;
            ac.Description = hov.actionn.Description;
            ac.Type = 1;
            ac.Amount = Convert.ToDecimal(hov.actionn.Amount);
            ac.Date = DateTime.Now;
            db.Action.Add(ac);
            db.SaveChanges();
            return RedirectToAction("Home", "Home");
            
        }
        [_SessionControl]
        [HttpGet]
        public ActionResult ButcendenCikar()
        {
            if (Kontrol() != null) return Kontrol();
            string uid = User.Identity.Name;
            HomeVar homeVar = new HomeVar();
            homeVar.user = db.Users.Where(x => x.UID.ToString() == uid).FirstOrDefault();
            homeVar.listBudgets = (from n in db.Budgets join c in db.Joins on n.BID equals c.BID orderby n.CreatedDate descending where c.UID == homeVar.user.UID select n).ToList();
            homeVar.listActions = db.Action.Where(x => x.UID == homeVar.user.UID).ToList();
            return View(homeVar);
        }
        [_SessionControl]
        [HttpPost]
        public ActionResult ButcendenCikar(HomeVar hv)
        {
            if (Kontrol() != null) return Kontrol();
            //if (ModelState.IsValid)
            {
                string uid = User.Identity.Name;
                Models.Action ac = new Models.Action();
                ac.UID = Convert.ToInt32(uid);
                ac.Amount = hv.actionn.Amount;
                ac.BID = hv.actionn.BID;
                ac.Description = hv.actionn.Description;
                ac.Type = 0;
                ac.Date = DateTime.Now;
                db.Action.Add(ac);
                db.SaveChanges();
                return RedirectToAction("Home", "Home");
            }
            return View(hv);
        }
        [_SessionControl]
        [HttpGet]
        public ActionResult BilgileriniDegistir()
        {
            if (Kontrol() != null) return Kontrol();
            string uid = User.Identity.Name;
            HomeVar homeVar = new HomeVar();
            homeVar.user = db.Users.Where(x => x.UID.ToString() == uid).FirstOrDefault();
            homeVar.listBudgets = (from n in db.Budgets join c in db.Joins on n.BID equals c.BID orderby n.CreatedDate descending where c.UID == homeVar.user.UID select n).ToList();
            homeVar.listActions = db.Action.Where(x => x.UID == homeVar.user.UID).ToList();
            homeVar.listIller = db.Iller.ToList();
            return View(homeVar);
        }
        [_SessionControl]
        [HttpPost]
        public ActionResult BilgileriniDegistir(HomeVar hv)
        {
            if (Kontrol() != null) return Kontrol();
            //if (ModelState.IsValid)
            {
                string uid = User.Identity.Name;
                Users us = db.Users.Where(x => x.UID.ToString() == uid).FirstOrDefault();
                us.Ad = hv.user.Ad;
                us.Soyad = hv.user.Soyad;
                us.Email = hv.user.Email;
                us.Password = hv.user.Password;
                us.DefaultBudget = hv.user.DefaultBudget;
                us.Sehir = hv.user.Sehir;
                db.Entry(us).State = System.Data.Entity.EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Home", "Home");
            }
            return View(hv);
        }
        [_SessionControl]
        [HttpGet]
        public ActionResult TumButcelerim()
        {
            if (Kontrol() != null) return Kontrol();
            string uid = User.Identity.Name;
            HomeVar homeVar = new HomeVar();
            homeVar.user = db.Users.Where(x => x.UID.ToString() == uid).FirstOrDefault();
            homeVar.listBudgets = (from n in db.Budgets join c in db.Joins on n.BID equals c.BID orderby n.CreatedDate descending where c.UID == homeVar.user.UID select n).ToList();
            homeVar.listActions = db.Action.Where(x => x.UID == homeVar.user.UID).ToList();
            homeVar.listOncelikler = db.Oncelikler.ToList();
            homeVar.listBudgetTypes = db.BudgetTypes.ToList();
            var Error = RouteData.Values["id"];
            if (Error != null) ModelState.AddModelError("", "Varsayılan Bütçe Silinemez!");
            return View(homeVar);
        }
        [_SessionControl]
        public ActionResult ButceSil(int BID)
        {
            if (Kontrol() != null) return Kontrol();
            string uid = User.Identity.Name;
            Users us = db.Users.Where(x => x.UID.ToString() == uid).FirstOrDefault();
            if(us.DefaultBudget == BID)
            {
                //varsayılan bütçe silinemez.
                ModelState.AddModelError("", "EMail bulunmakta!");
                return RedirectToAction("TumButcelerim",new { ID = BID,Error = "Varsayılan bütçe silinemez!" });
            }
            else
            {
                //STORED PROCEDURE KULLANILDI...
                try
                {
                    db.ButceSil(BID);
                    db.SaveChanges();
                } catch(Exception a) { }
            }
            return RedirectToAction("TumButcelerim");
        }
        [HttpGet]
        [_SessionControl]
        public ActionResult ButceniPaylas()
        {
            if (Kontrol() != null) return Kontrol();
            string uid = User.Identity.Name;
            HomeVar homeVar = new HomeVar();
            homeVar.user = db.Users.Where(x => x.UID.ToString() == uid).FirstOrDefault();
            homeVar.listBudgets = (from n in db.Budgets join c in db.Joins on n.BID equals c.BID orderby n.CreatedDate descending where c.UID == homeVar.user.UID select n).ToList();
            homeVar.listActions = db.Action.Where(x => x.UID == homeVar.user.UID).ToList();
            var Error = RouteData.Values["id"];
            if (Error != null) homeVar.Error = "Bu maile ait bir kullanıcı bulunmamakta!";
            return View(homeVar);
        }
        [HttpPost]
        [_SessionControl]
        public ActionResult ButceniPaylas(HomeVar hv)
        {
            if (Kontrol() != null) return Kontrol();
            string uid = User.Identity.Name;
            Budgets bg = db.Budgets.Where(x => x.BID == hv.budget.BID).FirstOrDefault();
            if(bg != null) { 
            Users us = db.Users.Where(x => x.Email == hv.user.Email).FirstOrDefault();
            if(us != null)
            {
                Joins jn = new Joins();
                jn.BID = bg.BID;
                jn.UID = us.UID;
                db.Joins.Add(jn);
                db.SaveChanges();
                return RedirectToAction("Home");

            }
            else
            {
                return RedirectToAction("ButceniPaylas", new { ID = hv.budget.BID });
            }
            }
            else
            {
                return RedirectToAction("ButceniPaylas");
            }
        }
        public ActionResult ChangeLanguage(string lang)
        {
            new LanguageManager().SetLanguage(lang);
            return RedirectToAction("Index", "Home");
        }
    }
}