using CoursLink.Classe;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CoursLink
{
    class Program
    {
        static void Main(string[] args)
        {

            foreach (var vehicule in Vehicule.GetVehicules(150))
            {
                Console.WriteLine("Plaque d'immatriculation :");
                Console.WriteLine(vehicule.RegistrationNumber + Environment.NewLine);
                Console.WriteLine("Couleur du véhicule");
                Console.WriteLine(vehicule.Color + Environment.NewLine);
                Console.WriteLine("kilometrage du véhicule" );
                Console.WriteLine(vehicule.Mileage + Environment.NewLine);
                Console.WriteLine("Chevaux du véhicule");
                Console.WriteLine(vehicule.EnginePower + Environment.NewLine);
                Console.WriteLine("Marque du véhicule");
                Console.WriteLine(vehicule.Brand + Environment.NewLine);
                Console.WriteLine("Model du véhicule");
                Console.WriteLine(vehicule.Model + Environment.NewLine);
                Console.WriteLine("Arrivage du véhicule au concessionnaire");
                Console.WriteLine(vehicule.ArrivalDateTime + Environment.NewLine);
                Console.WriteLine("Nombre de porte du véhicule");
                Console.WriteLine(vehicule.DoorCount + Environment.NewLine);
                Console.WriteLine("Nombre de place dans le véhicule");
                Console.WriteLine(vehicule.SeatCount + Environment.NewLine);
                Console.WriteLine("gamme de location");
                Console.WriteLine(vehicule.RentalRange + Environment.NewLine);
                Console.WriteLine("prix de base de la location par jour");
                Console.WriteLine(vehicule.RentalBasePricePerDay + Environment.NewLine);
                Console.WriteLine("coef de la gamme de location");
                Console.WriteLine(vehicule.RangeCoef + Environment.NewLine);
                Console.WriteLine("Obtient le prix de location par jour");
                Console.WriteLine(vehicule.TotalRentalPricePerDay + Environment.NewLine);

                Console.ReadKey();
                Console.Clear();
            }
        }
    }
}
