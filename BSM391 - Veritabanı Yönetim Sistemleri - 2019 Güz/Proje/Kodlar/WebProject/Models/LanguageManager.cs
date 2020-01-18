using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Threading;
using System.Web;

namespace WebProject.Models
{
    public class LanguageManager
    {
        public static List<Languages> AvailableLanguages = new List<Languages> {
            new Languages {
                LanguageFullName = "Türkçe", LanguageCultureName = "TR"
            },
            new Languages {
                LanguageFullName = "English", LanguageCultureName = "EN"
            },
        };
        public static bool IsLanguageAvailable(string lang)
        {
            return AvailableLanguages.Where(a => a.LanguageCultureName.Equals(lang)).FirstOrDefault() != null ? true : false;
        }
        public static string GetDefaultLanguage()
        {
            return AvailableLanguages[0].LanguageCultureName;
        }
        public void SetLanguage(string languageSelect)
        {
            try
            {
                if (languageSelect != null)
                {
                    Thread.CurrentThread.CurrentCulture = CultureInfo.CreateSpecificCulture(languageSelect);
                    Thread.CurrentThread.CurrentUICulture = new CultureInfo(languageSelect);
                }

                HttpCookie cookie = new HttpCookie("language");
                cookie.Value = languageSelect;
                HttpContext.Current.Response.Cookies.Add(cookie);

            }
            catch (Exception) { }
        }
    }
    public class Languages
    {
        public string LanguageFullName
        {
            get;
            set;
        }
        public string LanguageCultureName
        {
            get;
            set;
        }
    }
}