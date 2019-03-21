using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Garage.Lib
{
    public partial class Rent
    {
        #region Fields

        private static Random _Random = new Random();

        private static string[] _DriversFirstName = new string[] { "tata", "toto", "titi", "Rara", "palpal" };

        private static string[] _DriversLastName = new string[] { "cud", "falo", "margue", "banane" };


        #endregion


        #region Methods

        public static IEnumerable<Vehicle> GenerateVehicules(int count)
        {
            for (int i = 0; i < count; i++)
            {
                Vehicle vehicule = new Vehicle();

                vehicule.RegistrationNumber = Guid.NewGuid().ToString();
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
