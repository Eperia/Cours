using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CoursLink.Classe
{
    class Gamme
    {
        private long _Id;

        public long Id
        {
            get { return _Id; }
            set { _Id = value; }
        }
        private string _RentalRange;

        public string RentalRange
        {
            get { return _RentalRange; }
            set { _RentalRange = value; }
        }

        private double _RangeCoef;

        public double RangeCoef
        {
            get { return _RangeCoef; }
            set { _RangeCoef = value; }
        }



    }
}
