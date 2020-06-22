using System;
using System.Collections.Generic;
using System.Data.Common;
using System.IO;
using System.Linq;
using System.Management;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace PCInfo
{
    class Program
    {
        static void Main(string[] args)
        {
            printDriveInfo();
            printVideControllerInfo();
            printMemoryInfo();

            Console.ReadKey();
        }

        static void printDriveInfo()
        {
            foreach(DriveInfo drive in DriveInfo.GetDrives())
            {
                Console.WriteLine("Название диска - {0}", drive.Name);
                Console.WriteLine("Тип диска - {0}", drive.DriveType);

                if (drive.IsReady)
                {
                    Console.WriteLine("Метка диска - {0}", drive.VolumeLabel);

                    Console.WriteLine("Тип файловой системы - {0}", drive.DriveFormat);

                    Console.WriteLine("Общее доступное место - {0} мб", GetSizeInMegabytes(drive.TotalSize));
                    Console.WriteLine("Всё свободное место - {0} мб", GetSizeInMegabytes(drive.TotalFreeSpace));
                    Console.WriteLine("Занятое место - {0} мб", GetSizeInMegabytes(drive.TotalSize) - GetSizeInMegabytes(drive.TotalFreeSpace));
                    Console.WriteLine("Свободное место, которое доступно пользователю - {0} мб",
                                GetSizeInMegabytes(drive.AvailableFreeSpace));
                }

                Console.WriteLine();
            }
        }

        static long GetSizeInMegabytes(long bytes)
        {
            return bytes / 1024 / 1024;
        }

        static void printVideControllerInfo()
        {
            ManagementObjectSearcher searcher2 = new ManagementObjectSearcher("root\\CIMV2", "SELECT * FROM Win32_VideoController");
            Console.WriteLine("------------- Видеокарта --------");
            foreach (ManagementObject queryObj in searcher2.Get())
            {
                Console.WriteLine("Название: {0}", queryObj["Caption"]);
                Console.WriteLine("Семейство: {0}", queryObj["VideoProcessor"]);
                Console.WriteLine("Объем: {0}", queryObj["AdapterRAM"]);
            }
        }

        static void printMemoryInfo()
        {
            ManagementObjectSearcher searcher12 = new ManagementObjectSearcher("root\\CIMV2", "SELECT * FROM Win32_PhysicalMemory");

            Console.WriteLine("------------- Оперативная память --------");
            foreach (ManagementObject queryObj in searcher12.Get())
            {
                Console.WriteLine("BankLabel: {0} ; Capacity: {1} Gb; Speed: {2} ", queryObj["BankLabel"],
                                  Math.Round(System.Convert.ToDouble(queryObj["Capacity"]) / 1024 / 1024 / 1024, 2),
                                   queryObj["Speed"]);
            }
        }
    }
}
