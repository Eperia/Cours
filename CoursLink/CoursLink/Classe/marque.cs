using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CoursLink.Classe
{
    class Marque
    {
        private long _Id;

        public long Id
        {
            get { return _Id; }
            set { _Id = value; }
        }
        private string _Brand;

        public string Brand
        {
            get { return _Brand; }
            set { _Brand = value; }
        }

    }
}
