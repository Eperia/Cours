using Garage.Lib;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace Garage.WPFClient.Model
{
    /// <summary>
    /// Logique d'interaction pour GestionModel.xaml
    /// </summary>
    public partial class GestionModel : Window
    {
        public GestionModel()
        {
            InitializeComponent();
            using (Entities entities = new Entities())
            {
                LvVehicle.ItemsSource = entities.Vehicles;
                LvVehicle.Items.Refresh();
            }
            
        }
    }
}
