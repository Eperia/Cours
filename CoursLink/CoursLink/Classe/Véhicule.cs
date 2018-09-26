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

        #region Fields

        /// <summary>
        ///     Immatriculation du véhicule.
        /// </summary>
        private string _RegistrationNumber;

        /// <summary>
        ///     Kilométrage du véhicule.
        /// </summary>
        private int _Mileage;

        /// <summary>
        ///     Date d'entrée dans le parc de location du véhicule.
        /// </summary>
        private DateTime _ArrivalDateTime;

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
        ///     Obtient le prix de location par jour.
        /// </summary>
        public double TotalRentalPricePerDay => RentalBasePricePerDay * RangeCoef;

        public long IdModel;

        #endregion

        #region Methods
        
        #endregion
    }
}

