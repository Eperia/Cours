using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CoursLink.Classe
{
    class Models
    {
        private long _Id;

        public long Id
        {
            get { return _Id; }
            set { _Id = value; }
        }
        private string _Model;

        public string Model
        {
            get { return _Model; }
            set { _Model = value; }
        }
        private int _EnginePower;

        public int EnginePower
        {
            get { return _EnginePower; }
            set { _EnginePower = value; }
        }
        private int _DoorCount;

        public int DoorCount
        {
            get { return _DoorCount; }
            set { _DoorCount = value; }
        }
        private int _SeatCount;

        public int SeatCount
        {
            get { return _SeatCount; }
            set { _SeatCount = value; }
        }

        public long IdBrand ;
        public long IdColor ;
        public long IdRental ;



    }
}
