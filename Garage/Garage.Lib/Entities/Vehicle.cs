using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Garage.Lib
{
    public partial class Vehicle
    {
        #region Fields

        private static Random _Random = new Random();



        private static int[] _EnginePowers = new int[] { 70, 90, 120, 140, 230 };

        private static string[] _Brands = new string[] { "Toyota", "Citroën", "Porsche", "Ferrari", "BMW" };

        private static string[] _Models = new string[] { "Carrera", "F50", "LaFerrari", "M3", "M5", "Prius", "i20", "C3", "C4", "C1", "Panamera", "Cayenne S" };

        private static int[] _DoorCounts = new int[] { 3, 5 };

        private static string[] _RentalRanges = new string[] { "Eco", "Luxe", "Standard" };

        #endregion

       
        #region Methods

        public static IEnumerable<Vehicle> GenerateVehicules(int count)
        {
            for (int i = 0; i < count; i++)
            {
                Vehicle vehicule = new Vehicle();

                vehicule.RegistrationNumber = Guid.NewGuid();
                vehicule.Color = _Colors[_Random.Next(0, _Colors.Length)];
                vehicule.ArrivalDate = DateTime.Now.Date.AddDays(-_Random.Next(0, 700));
                vehicule.Mileage = _Random.Next(0, 120000);
                vehicule.Brand = _Brands[_Random.Next(0, _Brands.Length)];
                vehicule.Model = _Models[_Random.Next(0, _Models.Length)];
                vehicule.DoorCount = _DoorCounts[_Random.Next(0, _DoorCounts.Length)];
                vehicule.SeatCount = _Random.Next(2, 7);
                vehicule.RentalRange = _RentalRanges[_Random.Next(0, _RentalRanges.Length)];
                vehicule.RentalBasePricePerDay = new decimal((_Random.NextDouble() * (80 - 10)) + 10);
                yield return vehicule;
            }
        }

        #endregion
    }
}
