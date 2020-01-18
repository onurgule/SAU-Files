using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace G171210021_P
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        /// @author Onur Osman Güle - G171210021
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new frmAna());
        }
    }
}
