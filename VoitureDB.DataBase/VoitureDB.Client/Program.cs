using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using VoitureDB.Lib;

namespace VoitureDB.Client
{
    class Program
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

        public static List<Voiture> GetVehicules(int vehiculeCount)
        {
            List<Voiture> result = new List<Voiture>();

            for (int i = 0; i < vehiculeCount; i++)
            {
                Voiture vehicule = new Voiture();

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
                vehicule.RentalBasePricePerDay = Math.Round((_Random.NextDouble() * 70) + 10, 2);

                result.Add(vehicule);
            }


            return result;
        }
        static void Main(string[] args)
        {
            using (Entities entities = new Entities())
            {
                /*  List<Voiture> voitures = GetVehicules(10000);
                  foreach (Voiture voiture in voitures)
                  {
                      entities.Voitures.Add(voiture);
                  }
                  entities.SaveChanges();
                  */
                string userChoice = "";
                string SearchBrand;
                string SearchModel;
                string SearchColor;
                int SearchDoorCounts;
                int SearchSeatCounts;
                int SearchMileage;
                int SearchEnginePower;
                double SearchTotalRentalPricePerDay;

                do
                {
                    #region Menu

                    Console.WriteLine("----");
                    Console.WriteLine("LINQ");
                    Console.WriteLine("----");

                    Console.WriteLine("1 - Afficher la liste complète");
                    //2 - Demander à l'utilisateur une marque et afficher les voitures de cette marque.
                    Console.WriteLine("2 - Afficher les voitures de la marque");
                    Console.WriteLine("3 - Afficher les voitures de la marque et triées par km");
                    Console.WriteLine("4 - Afficher le nombre de voitures de la marque");
                    Console.WriteLine("5 - Demander 2 dates et afficher les véhicules entrés pendant la période");
                    Console.WriteLine("6 - Afficher le véhicule qui a le plus de kilometre");
                    Console.WriteLine("7 - Moyenne des kilimetre dans le parc");
                    Console.WriteLine("8 - Moyenne du prix total du parc");
                    Console.WriteLine("9 - Afficher nombre de véhicule de chaque marque");
                    Console.WriteLine("10 - Rechercher");

                    Console.WriteLine("0 - Quitter");

                    userChoice = Console.ReadLine();
                    Console.Clear();
                    #endregion

                    switch (userChoice)
                    {
                        case "1":
                            #region ForEach
                            //foreach (Vehicule vehicule in Vehicule.GetVehicules(10))
                            //{
                            //    ShowVehicule(vehicule);
                            //}

                            //La classe List<T> expose une méthode ForEach qui permet de simplifier la syntaxe.
                            // vehicules.ForEach((vehicule) => ShowVehicule(vehicule));
                            foreach (Voiture voiture in entities.Voitures)
                            {
                                ShowVehicule(voiture);
                            }
                            //Il est possible d'avoir plusieurs instructions en ajoutant "{ }"
                            //Vehicule.GetVehicules(20).ForEach((vehicule) =>
                            //{
                            //    ShowVehicule(vehicule);
                            //    Console.ReadKey();
                            //});
                            #endregion
                            break;
                        case "2":
                            #region ForEach

                            Console.WriteLine("Entré la marque rechercher");
                            SearchBrand = Console.ReadLine().ToLower();

                            //vehicules.Where(vehicule => vehicule.Brand.ToLower().Contains(SearchBrand)).ToList().ForEach(vehicule => ShowVehicule(vehicule));
                            foreach (Voiture voiture in entities.Voitures.Where(voiture => voiture.Brand.ToLower().Contains(SearchBrand)).ToList())
                            {
                                ShowVehicule(voiture);
                            }
                            #endregion
                            break;
                        case "3":
                            #region ForEach

                            Console.WriteLine("Entré la marque rechercher");
                            SearchBrand = Console.ReadLine().ToLower();

                            // vehicules.Where(vehicule => vehicule.Brand.ToLower().Contains(SearchBrand)).OrderBy(vehicule => vehicule.Mileage).ToList().ForEach(vehicule => ShowVehicule(vehicule));
                            foreach (Voiture voiture in entities.Voitures.Where(voiture => voiture.Brand.ToLower().Contains(SearchBrand)).OrderBy(vehicule => vehicule.Mileage).ToList())
                            {
                                ShowVehicule(voiture);
                            }
                            #endregion
                            break;
                        case "4":
                            #region ForEach

                            Console.WriteLine("Entré la marque rechercher");
                            SearchBrand = Console.ReadLine().ToLower();

                            //Console.WriteLine(vehicules.Count(vehicule => vehicule.Brand.ToLower().Contains(SearchBrand)).ToString());

                            Console.WriteLine(entities.Voitures.Count(voiture => voiture.Brand.ToLower().Contains(SearchBrand)));

                            #endregion
                            break;
                        case "5":
                            #region ForEach



                            Console.WriteLine("Entré la 1ère date");
                            DateTime FirstDate = ValidateDate();

                            Console.WriteLine("Entré la 2ème date");
                            DateTime SecondDate = ValidateDate();

                            // vehicules.Where(vehicule => vehicule.ArrivalDateTime > FirstDate && vehicule.ArrivalDateTime < SecondDate).ToList().ForEach(vehicule => ShowVehicule(vehicule));
                            foreach (Voiture voiture in entities.Voitures.Where(voiture => voiture.ArrivalDateTime > FirstDate && voiture.ArrivalDateTime < SecondDate).ToList())
                            {
                                ShowVehicule(voiture);
                            }
                            #endregion
                            break;
                        case "6":
                            #region ForEach

                            //vehicules.Where(vehicule => vehicule.Mileage == vehicules.Max(vehiculeMileage => vehiculeMileage.Mileage)).ToList().ForEach(vehicule => ShowVehicule(vehicule));
                            foreach (Voiture voiture in entities.Voitures.Where(voiture => voiture.Mileage == entities.Voitures.Max(vehiculeMileage => vehiculeMileage.Mileage)).ToList())
                            {
                                ShowVehicule(voiture);
                            }
                            #endregion
                            break;
                        case "7":
                            #region ForEach

                            //Console.WriteLine(vehicules.Average(vehicule => vehicule.Mileage));
                            Console.WriteLine(entities.Voitures.Average(voiture => voiture.Mileage));
                            
                            #endregion
                            break;
                        case "8":
                            #region ForEach

                            //Console.WriteLine(vehicules.Average(vehicule => vehicule.TotalRentalPricePerDay));
                            // Console.WriteLine(entities.Voitures.Average(voiture => voiture.TotalRentalPricePerDay));

                            #endregion
                            break;
                        case "9":
                            #region ForEach

                            entities.Voitures.GroupBy(vehicule => vehicule.Brand).ToList().ForEach(grpBy => Console.WriteLine($"{grpBy.Key}  : {grpBy.Count()}"));
                            #endregion
                            break;
                        case "10":
                            string userChoiceRech;

                            IEnumerable<Voiture> query = entities.Voitures;

                            do
                            {
                                #region Switch
                                Console.WriteLine($"{query.Count()}  véhicule est/sont susceptible de vous intéresser");

                                Console.WriteLine("---Recherche---");
                                Console.WriteLine("1 - La marque");
                                Console.WriteLine("2 - Le modèle");
                                Console.WriteLine("3 - nombre de porte min");
                                Console.WriteLine("4 - nombre de porte max");
                                Console.WriteLine("5 - Nombre de sièges minimum");
                                Console.WriteLine("6 - Nombre de sièges maximum");
                                Console.WriteLine("7 - Nombre de kilometre minimum");
                                Console.WriteLine("8 - La couleur (Jaune, Rouge, Vert, Bleu, Blanc)");
                                Console.WriteLine("9 - Prix euros/J max");
                                Console.WriteLine("10 - Gamme de location (Eco, Standard ou Luxe)");
                                Console.WriteLine("11- Puissance du moteur minimum");
                                Console.WriteLine("12 - Puissance du moteur maximum");
                                Console.WriteLine("13 - Liste des voitures filtré");

                                Console.WriteLine("0 - Quitter");
                                userChoiceRech = Console.ReadLine();
                                Console.Clear();
                                switch (userChoiceRech)
                                {
                                    case "1":
                                        #region ForEach
                                        Console.WriteLine("Entré la marque :");
                                        SearchBrand = Console.ReadLine().ToLower();

                                        query = query.Where(vehicule => vehicule.Brand.ToLower().Contains(SearchBrand)).ToList();

                                        #endregion
                                        break;
                                    case "2":
                                        #region ForEach
                                        Console.WriteLine("Entré le Model :");
                                        SearchModel = Console.ReadLine().ToLower();
                                        query = query.Where(vehicule => vehicule.Model.ToLower().Contains(SearchModel)).ToList();


                                        #endregion
                                        break;
                                    case "3":
                                        #region ForEach
                                        Console.WriteLine("Entré le nombre de porte (min) :");
                                        SearchDoorCounts = ValidateNumber();
                                        query = query.Where(vehicule => vehicule.DoorCount >= SearchDoorCounts).ToList();

                                        #endregion
                                        break;
                                    case "4":
                                        #region ForEach

                                        Console.WriteLine("Entré le nombre de porte (max) :");
                                        SearchDoorCounts = ValidateNumber();
                                        query = query.Where(vehicule => vehicule.DoorCount <= SearchDoorCounts).ToList();

                                        #endregion
                                        break;
                                    case "5":
                                        #region ForEach

                                        Console.WriteLine("Entré le nombre de siège (min) :");
                                        SearchSeatCounts = ValidateNumber();
                                        query = query.Where(vehicule => vehicule.SeatCount >= SearchSeatCounts).ToList();

                                        #endregion
                                        break;
                                    case "6":
                                        #region ForEach

                                        Console.WriteLine("Entré le nombre de siège (max) :");
                                        SearchSeatCounts = ValidateNumber();
                                        query = query.Where(vehicule => vehicule.SeatCount <= SearchSeatCounts).ToList();

                                        #endregion
                                        break;
                                    case "7":
                                        #region ForEach

                                        Console.WriteLine("Entré le nombre de kilometre (min) :");
                                        SearchMileage = ValidateNumber();
                                        query = query.Where(vehicule => vehicule.Mileage >= SearchMileage).ToList();

                                        #endregion
                                        break;
                                    case "8":
                                        #region ForEach

                                        Console.WriteLine("Entré la couleur (Jaune, Rouge, Vert, Bleu, Blanc:");
                                        SearchColor = Console.ReadLine().ToLower();
                                        query = query.Where(vehicule => vehicule.Color.ToLower().Contains(SearchColor)).ToList();


                                        #endregion
                                        break;
                                    case "9":
                                        #region ForEach

                                        Console.WriteLine("Prix de la journée (max)");
                                        SearchTotalRentalPricePerDay = ValidateNumberDouble();
                                        //query = query.Where(vehicule => vehicule.TotalRentalPricePerDay > SearchTotalRentalPricePerDay).ToList();

                                        #endregion
                                        break;
                                    case "10":
                                        #region ForEach

                                        Console.WriteLine("Entré Gamme de location (Eco, Standard ou Luxe)");
                                        SearchColor = Console.ReadLine().ToLower();
                                        query = query.Where(vehicule => vehicule.RentalRange.ToLower().Contains(SearchColor)).ToList();

                                        #endregion
                                        break;
                                    case "11":
                                        #region ForEach

                                        Console.WriteLine("Entré le nombre de kilometre (min) :");
                                        SearchEnginePower = ValidateNumber();
                                        query = query.Where(vehicule => vehicule.EnginePower >= SearchEnginePower).ToList();

                                        #endregion
                                        break;
                                    case "12":
                                        #region ForEach

                                        Console.WriteLine("Entré le nombre de kilometre (max) :");
                                        SearchEnginePower = ValidateNumber();
                                        query = query.Where(vehicule => vehicule.EnginePower <= SearchEnginePower).ToList();

                                        #endregion
                                        break;
                                    case "13":

                                        ShowVehicule(query);
                                        Console.WriteLine("Appuer sur une touche pour quitter");
                                        Console.ReadKey();

                                        break;
                                    default:
                                        break;
                                }
                                Console.ReadKey();
                                Console.Clear();
                            } while (userChoiceRech != "0");
                            #endregion
                            break;

                        default:
                            break;
                    }
                    Console.ReadKey();
                    Console.Clear();
                } while (userChoice != "0");


                Console.WriteLine("Press any key to exit...");
                Console.ReadKey();
            }

        }
        static void ShowVehicule(Voiture voiture)
        {
            Console.WriteLine($"---[{voiture.RegistrationNumber}]---");
            Console.WriteLine($"{voiture.Brand} {voiture.Model} {voiture.Color} {voiture.EnginePower} ch, gamme {voiture.RentalRange}");
            Console.WriteLine($"{voiture.DoorCount} portes, {voiture.SeatCount} places, {voiture.Mileage} km ({voiture.ArrivalDateTime:d})");
            Console.WriteLine($"{voiture.RentalBasePricePerDay} EUR/j");
            Console.WriteLine();
        }
        static void ShowVehicule(IEnumerable<Voiture> voitures)
        {
            foreach (var voiture in voitures)
            {
                Console.WriteLine($"---[{voiture.RegistrationNumber}]---");
                Console.WriteLine($"{voiture.Brand} {voiture.Model} {voiture.Color} {voiture.EnginePower} ch, gamme {voiture.RentalRange}");
                Console.WriteLine($"{voiture.DoorCount} portes, {voiture.SeatCount} places, {voiture.Mileage} km ({voiture.ArrivalDateTime:d})");
                Console.WriteLine($"{voiture.RentalBasePricePerDay} EUR/j");
                Console.WriteLine();
            }

        }
        public static DateTime ValidateDate()
        {
            bool isDateValid;
            DateTime Date;

            do
            {
                isDateValid = DateTime.TryParse(Console.ReadLine(), out Date);
                if (!isDateValid)
                {
                    Console.WriteLine("Date invalide.");
                }

            } while (!isDateValid);

            return Date;
        }
        public static int ValidateNumber()
        {
            bool isNumberValid;
            int Number;

            do
            {
                isNumberValid = int.TryParse(Console.ReadLine(), out Number);
                if (!isNumberValid)
                {
                    Console.WriteLine("Nombre invalide.");
                }

            } while (!isNumberValid);

            return Number;
        }
        public static double ValidateNumberDouble()
        {
            bool isNumberValid;
            double Number;

            do
            {
                isNumberValid = double.TryParse(Console.ReadLine(), out Number);
                if (!isNumberValid)
                {
                    Console.WriteLine("Nombre invalide.");
                }

            } while (!isNumberValid);

            return Number;
        }


    }
}
