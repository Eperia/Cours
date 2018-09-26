using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CoursLink.Classe
{

    /// <summary>
    ///     Représente un véhicule dans un parc de location.
    /// </summary>
    class Vehicule
    {
        #region Static

        private static Random _Random = new Random();
        private static string[] _Colors = new string[] { "Jaune", "Rouge", "Vert", "Bleu", "Blanc" };
        private static int[] _EnginePowers = new int[] { 70, 90, 120, 180 };
        private static string[] _Brands = new string[] { "Ford", "Citroën", "BMW", "Toyota", "Dacia" };
        private static string[] _Models = new string[] { "208", "C3", "C4", "Focus", "Passat", "Polo", "Golf", "308" };
        private static int[] _DoorCounts = new int[] { 3, 5 };
        private static int[] _SeatCounts = new int[] { 2, 5, 7 };
        private static string[] _RentalRanges = new string[] { "Eco", "Standard", "Luxe" };

        #endregion

        #region Fields

        /// <summary>
        ///     Immatriculation du véhicule.
        /// </summary>
        private string _RegistrationNumber;

        /// <summary>
        ///     Couleur du véhicule.
        /// </summary>
        private string _Color;

        /// <summary>
        ///     Kilométrage du véhicule.
        /// </summary>
        private int _Mileage;

        /// <summary>
        ///     Puissance moteur du véhicule.
        /// </summary>
        private int _EnginePower;

        /// <summary>
        ///     Marque du véhicule.
        /// </summary>
        private string _Brand;

        /// <summary>
        ///     Modèle du véhicule.
        /// </summary>
        private string _Model;

        /// <summary>
        ///     Date d'entrée dans le parc de location du véhicule.
        /// </summary>
        private DateTime _ArrivalDateTime;

        /// <summary>
        ///     Nombre de porte du véhicule.
        /// </summary>
        private int _DoorCount;

        /// <summary>
        ///     Nombre de place dans le véhicule.
        /// </summary>
        private int _SeatCount;


        
        /// <summary>
        ///   Autre objet :  Gamme de location (Eco, Standard ou Luxe).
        /// </summary>
        private string _RentalRange;

        /// <summary>
        ///     Prix de base de la location par jour.
        /// </summary>
        private double _RentalBasePricePerDay;

        #endregion

        #region Properties

        /// <summary>
        ///     Obtient ou définit l'immatriculation du véhicule.
        /// </summary>
        public string RegistrationNumber
        {
            get
            {
                return _RegistrationNumber;
            }

            set
            {
                _RegistrationNumber = value;
            }
        }

        /// <summary>
        ///     Obtient ou définit la couleur du véhicule.
        /// </summary>
        public string Color
        {
            get
            {
                return _Color;
            }

            set
            {
                _Color = value;
            }
        }

        /// <summary>
        ///     Obtient ou définit le kilométrage du véhicule.
        /// </summary>
        public int Mileage
        {
            get
            {
                return _Mileage;
            }

            set
            {
                _Mileage = value;
            }
        }

        /// <summary>
        ///     Obtient ou définit la puissance moteur du véhicule.
        /// </summary>
        public int EnginePower
        {
            get
            {
                return _EnginePower;
            }

            set
            {
                _EnginePower = value;
            }
        }

        /// <summary>
        ///     Obtient ou définit la marque du véhicule.
        /// </summary>
        public string Brand
        {
            get
            {
                return _Brand;
            }

            set
            {
                _Brand = value;
            }
        }

        /// <summary>
        ///     Obtient ou définit le modèle du véhicule.
        /// </summary>
        public string Model
        {
            get
            {
                return _Model;
            }

            set
            {
                _Model = value;
            }
        }

        /// <summary>
        ///     Obtient ou définit la date d'entrée dans le parc de location du véhicule.
        /// </summary>
        public DateTime ArrivalDateTime
        {
            get
            {
                return _ArrivalDateTime;
            }

            set
            {
                _ArrivalDateTime = value;
            }
        }

        /// <summary>
        ///     Obtient ou définit le nombre de porte du véhicule.
        /// </summary>
        public int DoorCount
        {
            get
            {
                return _DoorCount;
            }

            set
            {
                _DoorCount = value;
            }
        }

        /// <summary>
        ///     Obtient ou définit le nombre de place dans le véhicule.
        /// </summary>
        public int SeatCount
        {
            get
            {
                return _SeatCount;
            }

            set
            {
                _SeatCount = value;
            }
        }

        /// <summary>
        ///    Obtient ou définit la gamme de location (Eco, Standard ou Luxe).
        /// </summary>
        public string RentalRange
        {
            get
            {
                return _RentalRange;
            }

            set
            {
                _RentalRange = value;
            }
        }

        /// <summary>
        ///     Obtient ou définit le  prix de base de la location par jour.
        /// </summary>
        public double RentalBasePricePerDay
        {
            get
            {
                return _RentalBasePricePerDay;
            }

            set
            {
                _RentalBasePricePerDay = value;
            }
        }

        /// <summary>
        ///     Obtient le coefficient appliqué au prix de la location. 
        /// </summary>
        public double RangeCoef
        {
            get
            {
                switch (RentalRange)
                {
                    case "Eco": return 0.80;
                    case "Standard": return 1;
                    case "Luxe": return 1.20;
                    default: return 1;
                }
            }
        }

        /// <summary>
        ///     Obtient le prix de location par jour.
        /// </summary>
        public double TotalRentalPricePerDay => RentalBasePricePerDay * RangeCoef;

        #endregion

        #region Methods

        public static List<Vehicule> GetVehicules(int vehiculeCount)
        {
            List<Vehicule> result = new List<Vehicule>();

            for (int i = 0; i < vehiculeCount; i++)
            {
                Vehicule vehicule = new Vehicule();

                vehicule.RegistrationNumber = Guid.NewGuid().ToString();
                vehicule.Color = _Colors[_Random.Next(0, _Colors.Length)];
                vehicule.Mileage = _Random.Next(0, 120000);
                vehicule.EnginePower = _EnginePowers[_Random.Next(0, _EnginePowers.Length)];
                vehicule.Brand = _Brands[_Random.Next(0, _Brands.Length)];
                vehicule.Model = _Models[_Random.Next(0, _Models.Length)];
                vehicule.ArrivalDateTime = DateTime.Now.Date.AddDays(-_Random.Next(0, 700));
                vehicule.DoorCount = _DoorCounts[_Random.Next(0, _DoorCounts.Length)];
                vehicule.SeatCount = _SeatCounts[_Random.Next(0, _SeatCounts.Length)];
                vehicule.RentalRange = _RentalRanges[_Random.Next(0, _RentalRanges.Length)];
                vehicule._RentalBasePricePerDay = Math.Round((_Random.NextDouble() * 70) + 10, 2);

                result.Add(vehicule);
            }


            return result;
        }

        #endregion
    }
}

