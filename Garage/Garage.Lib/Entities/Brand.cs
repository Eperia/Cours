using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Garage.Lib
{
    public partial class Brand
    {
        #region Fields

        private static string[] _Brands = new string[] { "Toyota", "Citroën", "Porsche", "Ferrari", "BMW" };

        #endregion



        #region Methods

        public static IEnumerable<Brand> GenerateVehicules()
        {
            for (int i = 0; i < _Brands.Count(); i++)
            {
                Brand brand = new Brand();

                brand.Name = _Brands[i] ;
                yield return brand;
            }
        }

        #endregion
    }
}
