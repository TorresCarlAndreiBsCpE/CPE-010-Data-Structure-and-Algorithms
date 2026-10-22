#include <iostream>
#include "classJob.h"
#include "classPrinter.h"

int main() {
    Printer office_Printer;
 
    std::cout << "=== Printer Simulation ===\n" << std::endl;
 
    std::cout << "Morning: several employees send jobs to the shared printer.\n";
    office_Printer.addJob("Carl", 7);
    office_Printer.addJob("Jerry", 12);
    office_Printer.addJob("Roy", 5);
 
    std::cout << std::endl;
    office_Printer.showQueue();
 
    std::cout << "\nThe printer starts working through the queue one job at a time.\n";
    office_Printer.processNextJob();   // Alice's job finishes first (FIFO)
 
    std::cout << "\nWhile the printer was busy, there are more jobs arriving:\n";
    office_Printer.addJob("Ryo", 3);
    office_Printer.addJob("Joaquin", 8);
 
    std::cout << std::endl;
    office_Printer.showQueue();
 
    std::cout << "\nThe printer keeps going until the queue is empty:\n";
    office_Printer.processAllJobs();
 
    std::cout << "One more job arrives after everything cleared out:\n";
    office_Printer.addJob("Kylian", 2);
    office_Printer.processAllJobs();
 
    return 0;
}
 
