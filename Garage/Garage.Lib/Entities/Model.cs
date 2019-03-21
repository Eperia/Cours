using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Garage.Lib
{
    public partial class Model
    {
        #region Fields

        private static Random _Random = new Random();

        private static string[] _Models = new string[] { "Carrera", "F50", "LaFerrari", "M3", "M5", "Prius", "i20", "C3", "C4", "C1", "Panamera", "Cayenne S" };

        private static int[] _DoorCounts = new int[] { 3, 5 };

        private static int[] _SeatCounts = new int[] { 2, 4 ,5 };

        #endregion


        #region Methods

        public static IEnumerable<Model> GenerateVehicules(int count)
        {
            using (Entities entities = new Entities())
            {
                
                for (int i = 0; i < count; i++)
                {
                    Model model = new Model();

                    model.Name = _Models[_Random.Next(0, _Models.Length)];
                    model.Brand = entities.Brands.Find(_Random.Next(1, 5));
                    model.DoorCount = _DoorCounts[_Random.Next(0, _DoorCounts.Length)]; 
                    model.SeatCount = _Random.Next(2, 7);
                    model.RentalRange = entities.RentalRanges.Find(_Random.Next(1, 3));



                    yield return model;
                }

            }
        }

        #endregion
    }
}
