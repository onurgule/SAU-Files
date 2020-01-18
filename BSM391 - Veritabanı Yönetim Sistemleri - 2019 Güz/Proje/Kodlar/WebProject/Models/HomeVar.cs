using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace WebProject.Models
{
    public class HomeVar
    {
        public Users user { get; set; }
        public List<Users> listUsers {get;set;}
        public List<Budgets> listBudgets { get; set; }
        public List<Action> listActions { get; set; }
        public List<Joins> listJoins { get; set; }
        public List<Iller> listIller { get; set; }
        public List<Diller> listDiller { get; set; }
        public List<BudgetTypes> listBudgetTypes { get; set; }
        public List<Oncelikler> listOncelikler { get; set; }
        public List<ParaBirimleri> listParaBirimleri { get; set; }
        public List<Kurlar> listKurlar { get; set; }
        public List<Girisler> listGirisler { get; set; }
        public List<Yetkiler> listYetkiler { get; set; }
        public Budgets budget {get;set;}
        public Action actionn { get; set; }
        public bool isAdmin { get; set; }
        public string Error { get; set; }
    }
}