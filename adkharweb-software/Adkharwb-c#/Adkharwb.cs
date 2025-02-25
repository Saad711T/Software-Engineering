using System;
using System.Windows.Forms;

namespace Adkharwb
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            this.Text = "Adkharwb Desktop";
            this.Icon = new System.Drawing.Icon("static/images/favicon.png");



            // تحديد المسار النسبي للملف
            string filePath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "index.html");

            // تحميل ملف HTML في WebView2
            webView21.Source = new Uri($"file:///{filePath.Replace("\\", "/")}");
        }
    }
}