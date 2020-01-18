using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace WebProject.Models
{
    public class Login
    {
        [Display(Name = "FirstName", ResourceType = typeof(Resource))]
        public string FirstName
        {
            get;
            set;
        }
        [Display(Name = "LastName", ResourceType = typeof(Resource))]
        public string LastName
        {
            get;
            set;
        }

        [Display(Name = "Email", ResourceType = typeof(Resource))]
        [Required(ErrorMessageResourceType = typeof(Resource), ErrorMessageResourceName = "EmailRequired")]
        [RegularExpression(@"^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$", ErrorMessageResourceType = typeof(Resource), ErrorMessageResourceName = "EmailInvalid")]
        public string Email
        {
            get;
            set;
        }
        [Display(Name = "Password", ResourceType = typeof(Resource))]
        [Required(ErrorMessageResourceType = typeof(Resource), ErrorMessageResourceName = "PasswordRequired")]
        public string Password
        {
            get;
            set;
        }
        [Display(Name = "City", ResourceType = typeof(Resource))]
        public int Sehir
        {
            get;
            set;
        }
    }
}