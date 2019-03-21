using CoursDB.DataLib;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CourDB.Client
{
    class Program
    {
        static void Main(string[] args)
        {
            using (Entities entities = new Entities())
            {
                Publisher publisher = new Publisher();
                publisher.Name = "Netflix Corporation";
                publisher.WebSite = "www.netlifx";
                publisher.MaxPublication = 15;


                entities.Publishers.Add(publisher);

                publisher = new Publisher();
                publisher.WebSite = "www.netlifx";
                publisher.MaxPublication = 15;

                entities.Publishers.Add(publisher);


                entities.SaveChanges();

            }
    }
            

        }
    }
}
