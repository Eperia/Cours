using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CoursLink.Classe
{
    class Couleur
    {
        private long _Id;

        public long Id
        {
            get { return _Id; }
            set { _Id = value; }
        }
        private string _Color;

        public string Color
        {
            get { return _Color; }
            set { _Color = value; }
        }


    }
}
