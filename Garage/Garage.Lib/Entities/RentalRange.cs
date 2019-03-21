using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Garage.Lib
{
    public partial class RentalRange
    {
        #region Fields

        private static Random _Random = new Random();

        private static string[] _RentalRanges = new string[] { "Eco", "Luxe", "Standard" };

        #endregion


        #region Methods

        public static IEnumerable<RentalRange> GenerateVehicules(int count)
        {
            for (int i = 0; i < _RentalRanges.Count(); i++)
            {
                RentalRange rentalRange = new RentalRange();

                rentalRange.Label = _RentalRanges[i];
               
                yield return rentalRange;
            }
        }

        #endregion
    }
}
