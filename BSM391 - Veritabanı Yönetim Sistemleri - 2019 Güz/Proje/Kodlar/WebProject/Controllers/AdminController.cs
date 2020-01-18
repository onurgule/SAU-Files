using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using WebProject.Models;

namespace WebProject.Controllers
{
    [_SessionControl]
    public class AdminController : Controller
    {
        // GET: Admin

        dbEntities db = new dbEntities();
        bool isAdmin()
        {
            string uid = User.Identity.Name;
            List<Users> lu = db.Users.Where(x => x.UID.ToString() == uid).ToList();
            if (lu.Count() > 0)
            {
                bool isAdmin = lu.FirstOrDefault().Yetki == 1 ? true : false;
                if (isAdmin) return true;
                else return false;
            }
            else return false;
        }
        public ActionResult Index()
        {
            if (isAdmin())
            {
                string uid = User.Identity.Name;
                HomeVar homeVar = new HomeVar();
                homeVar.user = db.Users.Where(x => x.UID.ToString() == uid).FirstOrDefault();
                homeVar.listBudgets = db.Budgets.ToList();
                homeVar.listJoins = db.Joins.Distinct().ToList();
                homeVar.listActions = db.Action.Distinct().ToList();
                homeVar.listUsers = db.Users.ToList();
                homeVar.listYetkiler = db.Yetkiler.ToList();
                return View(homeVar);
            }
            else
            {
                return RedirectToAction("Home", "Home");
            }
        }
        public ActionResult UserSil(int UID)
        {
            string uid = User.Identity.Name;
            bool isAdmin = db.Users.Where(x => x.UID.ToString() == uid || x.Yetki == 1).Count() > 0;
            if (isAdmin)
            {
                Users us = new Users();
                us = db.Users.Where(x => x.UID == UID).FirstOrDefault();
                db.Entry(us).State = System.Data.Entity.EntityState.Deleted;
                db.SaveChanges();
            }
            return RedirectToAction("Index");
        }
        public ActionResult UserAdmin(int UID)
        {
            string uid = User.Identity.Name;
            bool isAdmin = db.Users.Where(x => x.UID.ToString() == uid || x.Yetki == 1).Count() > 0;
            if (isAdmin)
            {
                Users us = new Users();
                us = db.Users.Where(x => x.UID == UID).FirstOrDefault();
                if (us.Yetki == 0) us.Yetki = 1;
                //else if (us.Yetki == 0) us.Yetki = 1;
                db.SaveChanges();
            }
            return RedirectToAction("Index");
        }
        public ActionResult Butceler()
        {
            if (isAdmin())
            {
                string uid = User.Identity.Name;
                HomeVar homeVar = new HomeVar();
                homeVar.user = db.Users.Where(x => x.UID.ToString() == uid).FirstOrDefault();
                homeVar.listBudgets = db.Budgets.ToList();
                homeVar.listJoins = db.Joins.Distinct().ToList();
                homeVar.listActions = db.Action.Distinct().ToList();
                homeVar.listUsers = db.Users.ToList();
                return View(homeVar);
            }
            else
            {
                return RedirectToAction("Home", "Home");
            }
        }
        public ActionResult Girisler()
        {
            if (isAdmin())
            {
                string uid = User.Identity.Name;
                HomeVar homeVar = new HomeVar();
                homeVar.user = db.Users.Where(x => x.UID.ToString() == uid).FirstOrDefault();
                homeVar.listBudgets = db.Budgets.ToList();
                homeVar.listJoins = db.Joins.Distinct().ToList();
                homeVar.listActions = db.Action.Distinct().ToList();
                homeVar.listUsers = db.Users.ToList();
                homeVar.listGirisler = (from g in db.Girisler join u in db.Users on g.UID equals u.UID orderby g.Date descending select g).ToList();
                return View(homeVar);
            }
            else
            {
                return RedirectToAction("Home", "Home");
            }
        }
        public ActionResult ButceSil(int BID)
        {
            string uid = User.Identity.Name;
            bool isAdmin = db.Users.Where(x => x.UID.ToString() == uid || x.Yetki == 1).Count() > 0;
            if (isAdmin)
            {
                List<Users> lub = db.Users.Where(x => x.DefaultBudget == BID).ToList();
                foreach (var item in lub)
                {
                    item.DefaultBudget = null;
                    db.Entry(item).State = System.Data.Entity.EntityState.Modified;
                    db.SaveChanges();
                }
                Budgets bg = new Budgets();
                bg = db.Budgets.Where(x => x.BID == BID).FirstOrDefault();
                db.Entry(bg).State = System.Data.Entity.EntityState.Deleted;
                db.SaveChanges();
            }
            return RedirectToAction("Index");
        }
        public ActionResult ChangeLanguage(string lang)
        {
            new LanguageManager().SetLanguage(lang);
            return RedirectToAction("Index", "Admin");
        }
    }
}