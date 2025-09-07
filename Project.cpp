#include<iostream>
#include<string>
#include<fstream>
using namespace std;

// Taking Inputs
void getInputs(string& username, string& password, float& energy, float& housesize, int& areahouse, int& numRooms, float& sunlightHours, float& wireLen) {
	int choice;
	int weather;
	// Energy input
	do {
		cout << "Enter your preffered Input method for your Energy requirements: \n";
		cout << "1. Enter Monthly Energy consumption\n";
		cout << "2. Enter Yearly Energy consumption\n";
		cout << "3. Enter consumption per_Appliance\n";
		cout << "Enter your choice (1-3): ";
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while (choice != 1 && choice != 2 && choice != 3);
	cout << endl;


	if (choice == 1) {
		do {
			cout << "Enter your Monthly Energy Consumption (kWh): ";
			cin >> energy;
			if (energy <= 0) {
				cout << "Invalid Input! Please Try Again.\n";
			}
		} while (energy <= 0);
	}
	else if (choice == 2) {
		do {
			cout << "Enter your Yearly Energy Consumption (kWh): ";
			cin >> energy;
			if (energy <= 0) {
				cout << "Invalid Input! Please Try Again.\n";
			}
		} while (energy <= 0);
		energy = energy / 12;
		cout << "Your avg Monthly Consumption (kWh) is: " << energy << endl;
	}
	else if (choice == 3) {
		int numAppliances;
		float AppEnergy, hoursperDay, DaysperMonth;
		do {
			cout << "Enter number of Appliances: ";
			cin >> numAppliances;
			if (numAppliances <= 0) {
				cout << "Invalid Input! Please Try Again.\n";
			}
		} while (numAppliances <= 0);
		energy = 0;
		for (int i = 1; i <= numAppliances; i++) {
			cout << "For Appliance " << i << " : \n";
			do {
				cout << "Enter Power-Rating of Appliance (Wh) : ";
				cin >> AppEnergy;
				if (AppEnergy <= 0) {
					cout << "Invalid Input! Please Try Again.\n";
				}
			} while (AppEnergy <= 0);
			do {
				cout << "Enter avg usage Hours per day: ";
				cin >> hoursperDay;
				if (hoursperDay <= 0 || hoursperDay > 24) {
					cout << "Invalid Input! Please Try Again.\n";
				}
			} while (hoursperDay <= 0 || hoursperDay > 24);
			do {
				cout << "Enter avg usage Days per month : ";
				cin >> DaysperMonth;
				if (DaysperMonth <= 0 || DaysperMonth > 31) {
					cout << "Invalid Input! Please Try Again.\n";
				}
			} while (DaysperMonth <= 0 || DaysperMonth > 31);

			energy = energy + ((AppEnergy * hoursperDay * DaysperMonth) / 1000);
		}
		cout << "Your avg Monthly Consumption (kWh) is: " << energy << endl;
	}


	// Taking House Credentials
	cout << "Select Area of your house (Marlas) : \n";
	cout << "1. 3-Marlas\n";
	cout << "2. 5-Marlas\n";
	cout << "3. 7-Marlas\n";
	cout << "4. 10-Marlas\n";
	cout << "5. 12-Marlas\n";
	cout << "6. 20-Marlas ( Kanal)\n";
	cout << "7. 25-Marla ( Kanal)s\n";
	cout << "8. 30-Marlas\n";
	cout << "9. 40-Marlas\n";
	do {
		cout << "Enter your choice: ";
		cin >> areahouse;
		if (areahouse <= 0 || areahouse>9) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while (areahouse <= 0 || areahouse > 9);
	cout << endl;

	cout << "Enter location of your house for weather conditions: \n";
	cout << "1. Northern Areas\n";
	cout << "2. Western Areas\n";
	cout << "3. Central & Southern Punjab\n";
	cout << "4. Eastern Punjab\n";
	cout << "5. Sindh\n";
	cout << "6. Coastal Areas\n";
	do {
		cout << "Enter your choice: ";
		cin >> weather;
		if (weather < 1 || weather >6) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while (weather < 1 || weather >6);
	cout << endl;

	do {
		cout << "Enter total roof area of your house exposed to direct Sunlight (sq.meter) : ";
		cin >> housesize;
		if (housesize <= 0) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while (housesize <= 0);
	do {
		cout << "Enter number of Rooms of your house: ";
		cin >> numRooms;
		if (numRooms <= 0) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while (numRooms <= 0);
	do {
		cout << "Enter number of peak sunlight Hours in your area: ";
		cin >> sunlightHours;
		if (sunlightHours <= 0) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while (sunlightHours <= 0);
	do {
		cout << "Enter the distance from RoofTop to Main Electric Panel (wire length): ";
		cin >> wireLen;
		if (wireLen <= 0) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while (wireLen <= 0);

}



//// Storing data in Struct
struct Profile {
	string username;
	string password;
	float energy;
	int areahouse;
	int numRooms;
	float housesize;
	string plateType;
	float numPlates;
	float platesCost;
	float Savings;
	string inverterType;
	float InverterCost;
	string wireType;
	float WireCost;
	string batteryType;
	float BatteryCost;
	int numBatteries;
	float MeteringCost;
	float installationCost;
	float MaintainenceCost;
	float totalCost;

};


// Displaying Menu for Plates
void SolarMenu(string plateType[7], int panelWatt[7], float panelEff[7], float sizePlate[7], float platePrice[7]) {

	cout << "\t################################################\n";
	cout << "\t################################################\n";
	cout << "\t##                                            ##\n";
	cout << "\t##              SOLAR PANELS MENU             ##\n";
	cout << "\t##                                            ##\n";
	cout << "\t################################################\n";
	cout << "\t################################################\n\n";


	// Display Menu
	cout << "Available Solar Panels are: \n";
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ". " << plateType[i] << " - " << panelWatt[i] << " Watt with Efficiency of " << panelEff[i] * 100 << "% and panel Size " << sizePlate[i] << " (sq. meter) costing PKR. " << platePrice[i] << endl;
	}
	cout << endl;
}


// Recommending Panel Type and calculating Number of Plates required
void SolarPanelType(float energy, float& EnergyProduced, float houseSize, float sunlightHours, float& numPlates, string plateType[7], int panelWatt[7], float panelEff[7], float sizePlate[7], float platePrice[7], float& totalCost, Profile& profile, float& platesCost, string& plateChoosen) {
	int panelchoice, wattRecomm, indexpanel;
	string typeRecomm;
	float effRecomm, sizeRecomm, priceRecomm, areaPlates;
	if (energy >= 3500) {
		typeRecomm = plateType[2];
		wattRecomm = panelWatt[2];
		effRecomm = panelEff[2];
		sizeRecomm = sizePlate[2];
		priceRecomm = platePrice[2];
	}
	else if (energy >= 2500 && energy < 3500) {
		typeRecomm = plateType[1];
		wattRecomm = panelWatt[1];
		effRecomm = panelEff[1];
		sizeRecomm = sizePlate[1];
		priceRecomm = platePrice[1];
	}
	else if (energy >= 1800 && energy < 2500) {
		typeRecomm = plateType[0];
		wattRecomm = panelWatt[0];
		effRecomm = panelEff[0];
		sizeRecomm = sizePlate[0];
		priceRecomm = platePrice[0];
	}
	else if (energy >= 1200 && energy < 1800) {
		typeRecomm = plateType[4];
		wattRecomm = panelWatt[4];
		effRecomm = panelEff[4];
		sizeRecomm = sizePlate[4];
		priceRecomm = platePrice[4];
	}
	else if (energy >= 800 && energy < 1200) {
		typeRecomm = plateType[3];
		wattRecomm = panelWatt[3];
		effRecomm = panelEff[3];
		sizeRecomm = sizePlate[3];
		priceRecomm = platePrice[3];
	}
	else if (energy >= 500 && energy < 800) {
		typeRecomm = plateType[6];
		wattRecomm = panelWatt[6];
		effRecomm = panelEff[6];
		sizeRecomm = sizePlate[6];
		priceRecomm = platePrice[6];
	}
	else if (energy < 500) {
		typeRecomm = plateType[5];
		wattRecomm = panelWatt[5];
		effRecomm = panelEff[5];
		sizeRecomm = sizePlate[5];
		priceRecomm = platePrice[5];
	}



	do {
		SolarMenu(plateType, panelWatt, panelEff, sizePlate, platePrice);
		cout << "Our Recommendation for your credentials is " << typeRecomm << " - " << wattRecomm << " with Efficiency of " << effRecomm * 100 << "% and panel Size " << sizeRecomm << " (sq. meter) costing PKR. " << priceRecomm << endl<<endl;
		do {
			cout << "Enter the Index number for the Panel Type of your choice: ";
			cin >> indexpanel;
			if (indexpanel < 1 || indexpanel>7) {
				cout << "Invalid Input! Please Try Again.\n";
			}
		} while (indexpanel < 1 || indexpanel>7);
		cout << "You choosed " << plateType[indexpanel - 1] << " - " << panelWatt[indexpanel - 1] << " with Efficiency of " << panelEff[indexpanel - 1] * 100 << "% and panel Size " << sizePlate[indexpanel - 1] << " (sq. meter) costing PKR. " << platePrice[indexpanel - 1] << endl<<endl;


		// Calculating Energy produced by Recommended plate
		EnergyProduced = (panelWatt[indexpanel - 1] * panelEff[indexpanel - 1] * sunlightHours) / 1000;

		// Calculating Number of plates and Price
		numPlates = energy / (EnergyProduced * 30);

		int convNum = static_cast<int>(numPlates);
		if (numPlates > convNum) {
			convNum++;
		}
		numPlates = static_cast<float>(convNum);
		cout << "Required number of Plates of your choosen Type is : " << numPlates << endl;


		// Calculating Area of selected plates
		areaPlates = sizePlate[indexpanel - 1] * numPlates;

		if (areaPlates > houseSize) {
			cout << "Area of required plates of your choosen panel type exceeds your Roofsize. Please pick another Type.\n";
			cout << endl;

		}

	} while (areaPlates > houseSize);


	plateChoosen = plateType[indexpanel - 1];


	platesCost = platePrice[indexpanel - 1] * numPlates;
	cout << "Solar Plates for your Energy Requirements Costs: " << platesCost << endl<<endl;

	totalCost += platesCost;

}


// Potential Savings
void savings(float EnergyProduced, float numPlates, Profile& profile, float& Savings) {
	float ElectricCost = 0;

	float energyMonthly = EnergyProduced * numPlates * 30;

	if (energyMonthly < 50) {
		ElectricCost = 6.85;
	}
	else if (energyMonthly >= 50 && energyMonthly <= 100) {
		ElectricCost = 9.95;
	}
	else if (energyMonthly >= 101 && energyMonthly <= 200) {
		ElectricCost = 19.95;
	}
	else if (energyMonthly >= 201 && energyMonthly <= 300) {
		ElectricCost = 26.89;
	}
	else if (energyMonthly >= 301 && energyMonthly <= 700) {
		ElectricCost = 29.93;
	}
	else if (energyMonthly > 700) {
		ElectricCost = 35.26;
	}

	Savings = energyMonthly * ElectricCost;
	cout << "By having Solar System incorporated, Your Monthly Savings are PKR. " << Savings << endl;
	cout << "By having Solar System incorporated, Your Yearly Savings are PKR. " << Savings * 12 << endl<<endl;

}



// Displaying Menu for Inverters
void InverterMenu(string inverterType[7], int inverterWatt[7], float inverterPrice[7]) {

	cout << "\t################################################\n";
	cout << "\t################################################\n";
	cout << "\t##                                            ##\n";
	cout << "\t##               INVERTERS MENU               ##\n";
	cout << "\t##                                            ##\n";
	cout << "\t################################################\n";
	cout << "\t################################################\n\n";

	// Display Menu
	cout << "Available Inverters are: \n";
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ". " << inverterType[i] << " - " << inverterWatt[i] << " Watt costing PKR. " << inverterPrice[i] << endl;
	}
	cout << endl;

}


// Recommending Invertor Type
void InvertorType(string inveterType[7], int inverterWatt[7], float inverterPrice[7], float energy, float& totalCost, Profile& profile, float& InverterCost, string& inveterChoosen) {

	int InvWattRec, indexinverter;
	float InvPriceRec;
	string InvTypeRec;

	if (energy >= 3500) {
		InvTypeRec = inveterType[2];
		InvWattRec = inverterWatt[2];
		InvPriceRec = inverterPrice[2];
	}
	else if (energy >= 2500 && energy < 3500) {
		InvTypeRec = inveterType[1];
		InvWattRec = inverterWatt[1];
		InvPriceRec = inverterPrice[1];
	}
	else if (energy >= 1800 && energy < 2500) {
		InvTypeRec = inveterType[0];
		InvWattRec = inverterWatt[0];
		InvPriceRec = inverterPrice[0];
	}
	else if (energy >= 1200 && energy < 1800) {
		InvTypeRec = inveterType[4];
		InvWattRec = inverterWatt[4];
		InvPriceRec = inverterPrice[4];
	}
	else if (energy >= 800 && energy < 1200) {
		InvTypeRec = inveterType[3];
		InvWattRec = inverterWatt[3];
		InvPriceRec = inverterPrice[3];
	}
	else if (energy >= 500 && energy < 800) {
		InvTypeRec = inveterType[6];
		InvWattRec = inverterWatt[6];
		InvPriceRec = inverterPrice[6];
	}
	else if (energy < 500) {
		InvTypeRec = inveterType[5];
		InvWattRec = inverterWatt[5];
		InvPriceRec = inverterPrice[5];
	}


	InverterMenu(inveterType, inverterWatt, inverterPrice);
	cout << "Our Recommendation for your credentials is " << InvTypeRec << " - " << InvWattRec << " Watt costing PKR. " << InvPriceRec << endl<<endl;
	do {
		cout << "Enter the Index number for the Inverter Type of your choice: ";
		cin >> indexinverter;
		if (indexinverter < 1 || indexinverter>7) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while (indexinverter < 1 || indexinverter>7);
	cout << "You choosed " << inveterType[indexinverter - 1] << " - " << inverterWatt[indexinverter - 1] << " costing PKR. " << inverterPrice[indexinverter - 1] << endl<<endl;

	inveterChoosen = inveterType[indexinverter - 1];

	InverterCost = inverterPrice[indexinverter - 1];
	cout << "Total Cost of Recommended Inverter is: " << InverterCost << endl<<endl;

	totalCost += InverterCost;

}


// Displaying Menu for Wire
void WireMenu(string wireType[7], float wireDiameter[7], float wirePrice[7]) {

	cout << "\t################################################\n";
	cout << "\t################################################\n";
	cout << "\t##                                            ##\n";
	cout << "\t##                 WIRE MENU                  ##\n";
	cout << "\t##                                            ##\n";
	cout << "\t################################################\n";
	cout << "\t################################################\n\n";

	// Display Menu
	cout << "Available Types of Wire are: \n";
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ". " << wireType[i] << " wire with Diameter of " << wireDiameter[i] << " (mm^2) costing PKR. " << wirePrice[i] << " per meter.\n";
	}
	cout << endl;

}


// Recommending Wire Type
void WireType(string wireType[7], float wirePrice[7], float wireDiameter[7], float energy, float wireLen, float& wirePriceRec, float& totalCost, Profile& profile, float& WireCost, string& wireChoosen) {
	string wireTypeRec;
	int indexwire;

	if (energy >= 3500) {
		wireTypeRec = wireType[2];
		wirePriceRec = wirePrice[2];
	}
	else if (energy >= 2500 && energy < 3500) {
		wireTypeRec = wireType[1];
		wirePriceRec = wirePrice[1];
	}
	else if (energy >= 1800 && energy < 2500) {
		wireTypeRec = wireType[0];
		wirePriceRec = wirePrice[0];
	}
	else if (energy >= 1200 && energy < 1800) {
		wireTypeRec = wireType[4];
		wirePriceRec = wirePrice[4];
	}
	else if (energy >= 800 && energy < 1200) {
		wireTypeRec = wireType[3];
		wirePriceRec = wirePrice[3];
	}
	else if (energy >= 500 && energy < 800) {
		wireTypeRec = wireType[6];
		wirePriceRec = wirePrice[6];
	}
	else if (energy < 500) {
		wireTypeRec = wireType[5];
		wirePriceRec = wirePrice[5];
	}


	WireMenu(wireType, wireDiameter, wirePrice);
	cout << "Our Recommendation for your credentials is " << wireTypeRec << " costing PKR. " << wirePriceRec << " per meter.\n\n";
	do {
		cout << "Enter the Index number for the Wire Type of your choice: ";
		cin >> indexwire;
		if (indexwire < 1 || indexwire>7) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while (indexwire < 1 || indexwire>7);
	cout << "You choosed " << wireType[indexwire - 1] << " wire of Diameter " << wireDiameter[indexwire - 1] << " (mm^2) costing PKR. " << wirePrice[indexwire - 1] << endl<<endl;

	wireChoosen = wireType[indexwire - 1];

	// Calculating Cost of wire
	WireCost = wirePrice[indexwire - 1] * wireLen;
	cout << "Total Cost of Wire is: " << WireCost << endl<<endl;

	totalCost += WireCost;

}


// Net Metering installation
void NetMetering(float& wirePriceRec, float& totalCost, Profile& profile, float& MeteringCost) {
	char meteringchoice;
	int greenMeter = 30000, meterInstallation = 15000, lisence = 7500;
	float distMeter;
	do {
		cout << "Do you want Net-Metering?\n";
		cout << "Input 'Y' for Yes OR 'N' for No\n";
		cin >> meteringchoice;
	} while ((meteringchoice != 'Y') && (meteringchoice != 'y') && (meteringchoice != 'N') && (meteringchoice != 'n'));

	if (meteringchoice == 'Y' || meteringchoice == 'y') {
		// Calculating cost of wire for metering
		do {
			cout << "Enter distance (meter) of Main Electric Panel of house to Site for placing Green-Meter: ";
			cin >> distMeter;
			if (distMeter <= 0) {
				cout << "Invalid Input! Please Try Again.\n";
			}
		} while (distMeter <= 0);
		cout << endl;

		float MeterWiringCost = distMeter * wirePriceRec;

		//cost of metering
		cout << "Green-Meter costs PKR. " << greenMeter << endl;
		cout << "Wiring cost for Green-Metering " << MeterWiringCost << endl;
		cout << "Installation fee for Green-Meter is PKR. " << meterInstallation << endl;
		cout << "Lisence fee for Green-Metering (payable to Govt.) is PKR. " << lisence << endl;

		MeteringCost = greenMeter + MeterWiringCost + meterInstallation;
		cout << "Total Green-Metering will cost PKR. " << MeteringCost << " + Lisence fee (payable to Govt.) PKR. " << lisence << endl<<endl;

		totalCost += MeteringCost;
	}
	else {
		MeteringCost = 0;
	}
}


// Displaying Menu for Batteries
void BatteryMenu(string batteryType[7], int PowerBattery[7], float RangeBattery[7], float batteryPrice[7]) {
	cout << "\t################################################\n";
	cout << "\t################################################\n";
	cout << "\t##                                            ##\n";
	cout << "\t##                 BATTERY MENU               ##\n";
	cout << "\t##                                            ##\n";
	cout << "\t################################################\n";
	cout << "\t################################################\n\n";

	// Display Menu
	cout << "Available Battery Types are: ";
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ". " << batteryType[i] << " - " << PowerBattery[i] << " (AH) with the average Runtime of " << RangeBattery[i] << " hours costing PKR. " << batteryPrice[i] << endl;
	}
	cout << endl;

}

// Battery Installation
void BatteryOpt(string batteryType[7], int PowerBattery[7], float RangeBattery[7], float batteryPrice[7], float& totalCost, Profile& profile, float& BatteryCost, string& batteryChoosen, int& numBatteries) {
	char batteryChoice;
	int indexbattery;
	do {
		cout << "Do you want Batteries for Backup at Night?\n";
		cout << "Input 'Y' for Yes OR 'N' for No\n";
		cin >> batteryChoice;
		if ((batteryChoice != 'Y') && (batteryChoice != 'y') && (batteryChoice != 'N') && (batteryChoice != 'n')) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while ((batteryChoice != 'Y') && (batteryChoice != 'y') && (batteryChoice != 'N') && (batteryChoice != 'n'));

	if (batteryChoice == 'Y' || batteryChoice == 'y') {
		do {
			BatteryMenu(batteryType, PowerBattery, RangeBattery, batteryPrice);
			cout << "Enter the Index number for Battery of your choice: ";
			cin >> indexbattery;
			if (indexbattery < 1 || indexbattery>7) {
				cout << "Invalid Input! Please Try Again.\n";
			}
		} while (indexbattery < 1 || indexbattery>7);
		cout << "You choosed " << batteryType[indexbattery - 1] << " - " << PowerBattery[indexbattery - 1] << " (AH) with the average Runtime of " << RangeBattery[indexbattery - 1] << " hours costing PKR. " << batteryPrice[indexbattery - 1] << endl<<endl;

		// Calculating Number of Batteries
		do {
			cout << "Enter the number of choosen Batteries Required: ";
			cin >> numBatteries;
			if (numBatteries < 1) {
				cout << "Invalid Input! Please Try Again.\n";
			}
		} while (numBatteries < 1);


		batteryChoosen = batteryType[indexbattery - 1];

		// Calculating cost of batteries
		BatteryCost = batteryPrice[indexbattery - 1] * numBatteries;
		cout << "Cost of Batteries is PKR. " << BatteryCost << endl<<endl;

		totalCost += BatteryCost;

	}
	else {
		batteryChoosen = "None";
		BatteryCost = 0;
		numBatteries = 0;
	}

}


// Installation
void installationService(float numPlates, float& totalCost, Profile& profile, float& installationCost) {
	char installService;
	installationCost = 0;
	do {
		cout << "Do you want Installation Service?\n";
		cout << "Input 'Y' for Yes OR 'N' for No\n";
		cin >> installService;
		if ((installService != 'Y') && (installService != 'y') && (installService != 'N') && (installService != 'n')) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while ((installService != 'Y') && (installService != 'y') && (installService != 'N') && (installService != 'n'));

	if ((installService == 'Y') || (installService == 'y')) {
		if (numPlates <= 5) {
			installationCost = 10000;
		}
		else if (numPlates > 5 && numPlates <= 10) {
			installationCost = 15000;
		}
		else if (numPlates > 10 && numPlates <= 15) {
			installationCost = 20000;
		}
		else if (numPlates > 15 && numPlates <= 20) {
			installationCost = 20000;
		}
		else if (numPlates > 20) {
			installationCost = 30000;
		}

		cout << "Total Installation Cost including Labour and Material is: " << installationCost << endl<<endl;

		totalCost += installationCost;
	}
}


// Maintainance
void Maintainence(float& totalCost, Profile& profile, float& MaintainenceCost) {
	char maintainenceChoice;
	int Plan;
	float MonthlyPlan = 5000, YearlyPlan = 50000;
	MaintainenceCost = 0;
	do {
		cout << "Do you want Maintainence Service?\n";
		cout << "Input 'Y' for Yes OR 'N' for No\n";
		cin >> maintainenceChoice;
		if ((maintainenceChoice != 'Y') && (maintainenceChoice != 'y') && (maintainenceChoice != 'N') && (maintainenceChoice != 'n')) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while ((maintainenceChoice != 'Y') && (maintainenceChoice != 'y') && (maintainenceChoice != 'N') && (maintainenceChoice != 'n'));

	if ((maintainenceChoice == 'Y') || (maintainenceChoice == 'y')) {
		cout << "\t################################################\n";
		cout << "\t################################################\n";
		cout << "\t##                                            ##\n";
		cout << "\t##          MAINTAINENCE PLANS MENU           ##\n";
		cout << "\t##                                            ##\n";
		cout << "\t################################################\n";
		cout << "\t################################################\n\n";

		do {
			cout << "Available Plans are:\n";
			cout << "Enter 1 for Monthly Maintainence plan costing PKR. " << MonthlyPlan << endl;
			cout << "Enter 2 for Yearly Maintainence plan costing PKR. " << YearlyPlan << " (" << YearlyPlan / 12 << ") per month.\n";
			cout << "Enter your preffered Maintainence Plan: ";
			cin >> Plan;
			if (Plan != 1 && Plan != 2) {
				cout << "Invalid Input! Please Try Again.\n";
			}
		} while (Plan != 1 && Plan != 2);

		if (Plan == 1) {
			MaintainenceCost = MonthlyPlan;
		}
		else {
			MaintainenceCost = YearlyPlan;
		}

		cout << "Total maintainence Cost is: " << MaintainenceCost << endl<<endl;

		totalCost += MaintainenceCost;
	}
}

// Total Cost of System
void CostTotal(float& totalCost, Profile& profile) {
	cout << "Total Cost for Solar Setup for your credentials is PKR. " << totalCost << endl;

}





// Saving Profiles
void saveProfile(const Profile& profile) {
	ofstream profileFile("profiles.txt", ios::app);
	if (profileFile.is_open()) {
		profileFile << profile.username << " " << profile.password << endl;
		profileFile << profile.energy << " " << profile.areahouse << " " << profile.housesize << endl;
		profileFile << profile.plateType << " " << profile.platesCost << " " << profile.numPlates << endl;
		profileFile << profile.inverterType << " " << profile.InverterCost << endl;
		profileFile << profile.wireType << " " << profile.WireCost << endl;
		profileFile << profile.batteryType << endl << profile.BatteryCost << " " << profile.numBatteries << endl;
		profileFile << profile.MaintainenceCost << " " << profile.installationCost << " " << profile.MeteringCost << endl;
		profileFile << profile.totalCost << " " << profile.Savings << endl;

		cout << "Profile Saved Successfully!\n";
	}
	else {
		cout << "Saving Profile Failed!";
	}
	profileFile.close();
}


bool loadProfile(const string& username, const string& password, Profile& profile) {
	ifstream profileFile("profiles.txt");
	if (!profileFile.is_open()) {
		cout << "Failed to open profiles.txt. Ensure the file exists and path is correct.\n";
		return false;
	}

	Profile tempProfile;
	bool profileFound = false;

	while (profileFile >> tempProfile.username >> tempProfile.password) {
		// Read the rest of the profile fields

		profileFile >> tempProfile.energy >> tempProfile.areahouse >> tempProfile.housesize
			>> tempProfile.plateType >> tempProfile.platesCost >> tempProfile.numPlates
			>> tempProfile.inverterType >> tempProfile.InverterCost
			>> tempProfile.wireType >> tempProfile.WireCost
			>> tempProfile.batteryType >> tempProfile.BatteryCost >> tempProfile.numBatteries
			>> tempProfile.MaintainenceCost >> tempProfile.installationCost >> tempProfile.MeteringCost
			>> tempProfile.totalCost >> tempProfile.Savings;

		// Check if this is the required profile
		if (tempProfile.username == username && tempProfile.password == password) {
			profile = tempProfile;
			profileFound = true;
			break;  // Stop searching once the profile is found
		}
	}

	profileFile.close();

	if (profileFound) {
		cout << "Profile loaded successfully!\n";
		return true;
	}
	else {
		cout << "Profile not found.\n";
		return false;
	}
}


// Displaying profiles
void displayProfile(const Profile& profile) {
	cout << "Username: " << profile.username << endl;
	cout << "Energy requirement: " << profile.energy << endl;
	cout << "Area of house: " << profile.areahouse << endl;
	cout << "Area of roof: " << profile.housesize << endl;
	cout << "Plate Type: " << profile.plateType << endl;
	cout << "Plates cost: " << profile.platesCost << endl;
	cout << "Number of Plates: " << profile.numPlates << endl;
	cout << "Inverter Type: " << profile.inverterType << endl;
	cout << "Inverter Cost: " << profile.InverterCost << endl;
	cout << "Wire Type: " << profile.wireType << endl;
	cout << "Wire Cost: " << profile.WireCost << endl;
	cout << "Battery Type: " << profile.batteryType << endl;
	cout << "Battery Cost: " << profile.BatteryCost << endl;
	cout << "Number of Batteries: " << profile.numBatteries << endl;
	cout << "Net Metering Cost: " << profile.MeteringCost << endl;
	cout << "Maintenance Cost: " << profile.MaintainenceCost << endl;
	cout << "Installation Cost: " << profile.installationCost << endl;
	cout << "Total Cost: " << profile.totalCost << endl;
}


// Load All Profiles
void loadAllProfiles() {
	ifstream profileFile("profiles.txt");
	if (!profileFile.is_open()) {
		cout << "Failed to open profiles.txt. Ensure the file exists and path is correct.\n";
		return;
	}

	Profile tempProfile;
	cout << "Displaying all profiles:\n";

	while (profileFile >> tempProfile.username >> tempProfile.password) {
		// Read the rest of the profile fields
		profileFile >> tempProfile.energy
			>> tempProfile.areahouse
			>> tempProfile.housesize
			>> tempProfile.plateType
			>> tempProfile.platesCost
			>> tempProfile.numPlates
			>> tempProfile.inverterType
			>> tempProfile.InverterCost
			>> tempProfile.wireType
			>> tempProfile.WireCost
			>> tempProfile.batteryType
			>> tempProfile.BatteryCost
			>> tempProfile.numBatteries
			>> tempProfile.MaintainenceCost
			>> tempProfile.installationCost
			>> tempProfile.MeteringCost
			>> tempProfile.totalCost
			>> tempProfile.Savings;

		// Display the profile
		displayProfile(tempProfile);
		cout << "-----------------------------\n";
	}

	profileFile.close();
}


// Deleting Profile
void deleteProfile(const string& username, const string& password) {
	ifstream profileFile("profiles.txt");
	ofstream tempFile("temp.txt");
	if (!profileFile.is_open() || !tempFile.is_open()) {
		cerr << "Failed to open files for deletion operation.\n";
		return;
	}

	Profile tempProfile;
	bool profileFound = false;

	while (profileFile >> tempProfile.username >> tempProfile.password) {
		// Read the rest of the profile fields
		profileFile >> tempProfile.energy >> tempProfile.areahouse >> tempProfile.housesize
			>> tempProfile.plateType >> tempProfile.platesCost >> tempProfile.numPlates
			>> tempProfile.inverterType >> tempProfile.InverterCost
			>> tempProfile.wireType >> tempProfile.WireCost
			>> tempProfile.batteryType >> tempProfile.BatteryCost >> tempProfile.numBatteries
			>> tempProfile.MaintainenceCost >> tempProfile.installationCost >> tempProfile.MeteringCost
			>> tempProfile.totalCost >> tempProfile.Savings;

		// Write to temp file if profile doesn't match
		if (tempProfile.username != username && tempProfile.password != password) {
			tempFile << tempProfile.username << " " << tempProfile.password << endl
				<< tempProfile.energy << " " << tempProfile.areahouse << " " << tempProfile.housesize << endl
				<< tempProfile.plateType << " " << tempProfile.platesCost << " " << tempProfile.numPlates << endl
				<< tempProfile.inverterType << " " << tempProfile.InverterCost << endl
				<< tempProfile.wireType << " " << tempProfile.WireCost << endl
				<< tempProfile.batteryType << endl << tempProfile.BatteryCost << " " << tempProfile.numBatteries << endl
				<< tempProfile.MaintainenceCost << " " << tempProfile.installationCost << " " << tempProfile.MeteringCost << endl
				<< tempProfile.totalCost << " " << tempProfile.Savings << endl;
		}
		else {
			profileFound = true;
		}
	}

	profileFile.close();
	tempFile.close();

	// Replace the original file with the updated file
	if (profileFound) {
		remove("profiles.txt");
		rename("temp.txt", "profiles.txt");
		cout << "Profile deleted successfully.\n";
	}
	else {
		remove("temp.txt");
		cout << "Profile not found.\n";
	}
}



void backupProfiles(const string& backupFilename = "profiles_backup.txt") {
	ifstream originalFile("profiles.txt");
	ofstream backupFile(backupFilename);

	if (!originalFile.is_open()) {
		cout << "Failed to open the original profiles file for backup.\n";
		return;
	}
	if (!backupFile.is_open()) {
		cout << "Failed to create the backup file.\n";
		return;
	}

	// Copying content line by line
	string line;
	while (getline(originalFile, line)) {
		backupFile << line << endl;
	}

	cout << "Backup successfully created as " << backupFilename << ".\n";

	originalFile.close();
	backupFile.close();
}


void restoreProfiles(const string& backupFilename = "profiles_backup.txt") {
	ifstream backupFile(backupFilename);
	ofstream originalFile("profiles.txt");

	if (!backupFile.is_open()) {
		cout << "Failed to open the backup file for restoration.\n";
		return;
	}
	if (!originalFile.is_open()) {
		cout << "Failed to restore the original profiles file.\n";
		return;
	}

	// Copy content line by line
	string line;
	while (getline(backupFile, line)) {
		originalFile << line << endl;
	}

	cout << "Profiles successfully restored from " << backupFilename << ".\n";

	backupFile.close();
	originalFile.close();
}



void createNewProfile() {
	Profile profile;
	float totalCost = 0;

	// Giving plates Data
	string plateType[7] = { "Monocrystalline", "Monocrystalline", "Monocrystalline", "Polycrystalline","Polycrystalline", "Thin-Plate","Thin-Plate" };
	int panelWatt[7] = { 250,330,540,275,330,150,250 };
	float panelEff[7] = { 0.22,0.24,0.23,0.20,0.19,0.13,0.14 };
	float sizePlate[7] = { 1.60,1.95,2.57,1.6,1.95,1.05,1.28 };
	float platePrice[7] = { 25000,32000,55000,20000,28000,12000,18000 };

	// Giving Inverter Data
	string inverterType[7] = { "Hybrid","Hybrid","Central","String","Hybrid","String","String" };
	int inverterWatt[7] = { 2500,3500,5000,1200,1800,500,800 };
	float inverterPrice[7] = { 55000,65000,100000,30000,40000,15000,20000 };

	// Giving Wire Data
	string wireType[7] = { "Copper","Copper", "Copper", "Copper", "Copper", "Copper", "Copper" };
	float wireDiameter[7] = { 16,25,35,6,10,2.5,4 };
	float wirePrice[7] = { 200,300,400,100,150,50,75 };

	// Giving Battery Data
	string batteryType[7] = { "AGM-battery","AGM-battery", "AGM-battery", "Gel-battery","Gel-battery", "Lithmium-ion-Battery","Lithmium-ion-Battery" };
	int PowerBattery[7] = { 100,150,200,100,150,100,200 };
	float RangeBattery[7] = { 2.5,3.5,5,3.5,5.5,7,11 };
	float PriceBattery[7] = { 21000,31000,41000,23000,36500,62500,125000 };


	int numRooms, areahouse, numBatteries;
	float energy, EnergyProduced, houseSize, sunlightHours, wireLen, wirePriceRec, numPlates = 0, platesCost, WireCost, BatteryCost, InverterCost, MeteringCost, installationCost, MaintainenceCost, Savings;
	string username, password, plateChoosen, inverterChoosen, wireChoosen, batteryChoosen;


	//	// Getting Username and Password
	cout << "Enter a Username for Creating Profile: ";
	cin >> username;
	cout << "Enter a password for your profile: ";
	cin >> password;

	getInputs(username, password, energy, houseSize, areahouse, numRooms, sunlightHours, wireLen);
	SolarPanelType(energy, EnergyProduced, houseSize, sunlightHours, numPlates, plateType, panelWatt, panelEff, sizePlate, platePrice, totalCost, profile, platesCost, plateChoosen);
	savings(EnergyProduced, numPlates, profile, Savings);
	InvertorType(inverterType, inverterWatt, inverterPrice, energy, totalCost, profile, InverterCost, inverterChoosen);
	WireType(wireType, wirePrice, wireDiameter, energy, wireLen, wirePriceRec, totalCost, profile, WireCost, wireChoosen);
	NetMetering(wirePriceRec, totalCost, profile, MeteringCost);
	BatteryOpt(batteryType, PowerBattery, RangeBattery, PriceBattery, totalCost, profile, BatteryCost, batteryChoosen, numBatteries);
	installationService(numPlates, totalCost, profile, installationCost);
	Maintainence(totalCost, profile, MaintainenceCost);
	CostTotal(totalCost, profile);

	profile.username = username;
	profile.password = password;
	profile.energy = energy;
	profile.areahouse = areahouse;
	profile.housesize = houseSize;
	profile.plateType = plateChoosen;
	profile.platesCost = platesCost;
	profile.numPlates = numPlates;
	profile.inverterType = inverterChoosen;
	profile.InverterCost = InverterCost;
	profile.wireType = wireChoosen;
	profile.WireCost = WireCost;
	profile.batteryType = batteryChoosen;
	profile.BatteryCost = BatteryCost;
	profile.numBatteries = numBatteries;
	profile.MaintainenceCost = MaintainenceCost;
	profile.installationCost = installationCost;
	profile.MeteringCost = MeteringCost;
	profile.totalCost = totalCost;
	profile.Savings = Savings;

	saveProfile(profile);

}



// Open existing Profiles
void openProfiles() {
	Profile profile;
	string username, password;

	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	if (loadProfile(username, password, profile)) {
		displayProfile(profile);
	}
	else {
		cout << "Failed to load profile. Check username and password.\n";
	}
}


// View all Profiles
void viewAllProfiles() {
	cout << "Viewing All Profiles...\n";
	loadAllProfiles();
}


// Deleting Profile

void DeleteProfile() {
	string username;
	string password;
	char del;
	cout << "Enter the username of the profile to delete: ";
	cin >> username;
	cout << "Enter the password of the profile to delete: ";
	cin >> password;

	do {
		cout << "Are you sure you want to delete this profile?\n";
		cout << "Input 'Y' for Yes OR 'N' for No\n";
		cin >> del;
		if ((del != 'Y') && (del != 'y') && (del != 'N') && (del != 'n')) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while ((del != 'Y') && (del != 'y') && (del != 'N') && (del != 'n'));

	if ((del == 'Y') || (del == 'y')) {
		deleteProfile(username, password);
	}
}


// Exporting the report
void exportSummaryToCSV(const string& filename = "summary_report.csv") {
	ifstream profileFile("profiles.txt");
	ofstream csvFile(filename);

	if (!profileFile.is_open()) {
		cout << "Failed to open profiles.txt. Ensure the file exists.\n";
		return;
	}
	if (!csvFile.is_open()) {
		cout << "Failed to create summary report file.\n";
		return;
	}

	Profile tempProfile;

	// Write CSV Headers
	csvFile << "Username,Plate Type,Plates Cost,Number Panels,Inverter Type,Inverter Cost,Wire Type,Wire Cost,Battery Type,Battery Cost,Number Batteries,Maintainence Cost,Installation Cost,Net Meter Cost,Total Cost (PKR),Savings (PKR)\n";

	while (profileFile >> tempProfile.username >> tempProfile.password) {
		profileFile >> tempProfile.energy >> tempProfile.areahouse >> tempProfile.housesize
			>> tempProfile.plateType >> tempProfile.platesCost >> tempProfile.numPlates
			>> tempProfile.inverterType >> tempProfile.InverterCost
			>> tempProfile.wireType >> tempProfile.WireCost
			>> tempProfile.batteryType >> tempProfile.BatteryCost >> tempProfile.numBatteries
			>> tempProfile.MaintainenceCost >> tempProfile.installationCost >> tempProfile.MeteringCost
			>> tempProfile.totalCost >> tempProfile.Savings;

		csvFile << tempProfile.username << ","
			<< tempProfile.plateType << ","
			<< tempProfile.platesCost << ","
			<< tempProfile.numPlates << ","
			<< tempProfile.inverterType << ","
			<< tempProfile.InverterCost << ","
			<< tempProfile.wireType << ","
			<< tempProfile.WireCost << ","
			<< tempProfile.batteryType << ","
			<< tempProfile.BatteryCost << ","
			<< tempProfile.numBatteries << ","
			<< tempProfile.MaintainenceCost << ","
			<< tempProfile.installationCost << ","
			<< tempProfile.MeteringCost << ","
			<< tempProfile.totalCost << ","
			<< tempProfile.Savings << "\n";
	}

	cout << "Summary report successfully exported to " << filename << ".\n";

	profileFile.close();
	csvFile.close();
}


// Educational References
void moreInfo() {
	cout << "For more information on Solar Panels, Please visit the following link:-" << endl;
	cout << "https://www.mrsolar.com/what-is-a-solar-panel/" << endl;
	cout << "For information on How Solar works, Please visit the following link:-" << endl;
	cout << "https://aurorasolar.com/blog/how-do-solar-panels-work-everything-you-need-to-know/" << endl;
	cout << "For Solar Panel Installation Guide, Please visit the following link:-" << endl;
	cout << "https://www.skillstg.co.uk/blog/how-to-install-a-solar-panel/" << endl;

}



// Main Menu
void DisplayMainMenu() {

	cout << "\t################################################\n";
	cout << "\t################################################\n";
	cout << "\t##                                            ##\n";
	cout << "\t##                 MAIN MENU                  ##\n";
	cout << "\t##                                            ##\n";
	cout << "\t################################################\n";
	cout << "\t################################################\n\n";

	int choice;

	cout << " 1. Create New Profile\n 2. Open Existing Profile\n 3. View All Profiles\n 4. Delete a Profile\n 5. Generate Report of Profiles\n 6. More Information\n 7. Backup Profiles\n 8. Restore Profiles\n 9. Exit\n";
	do {
		cout << "Enter your Choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9) {
			cout << "Invalid Input! Please Try Again.\n";
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9);
	cout << endl;


	if (choice == 1) {
		createNewProfile();
	}
	else if (choice == 2) {
		openProfiles();
	}
	else if (choice == 3) {
		viewAllProfiles();
	}
	else if (choice == 4) {
		DeleteProfile();
	}
	else if (choice == 5) {
		exportSummaryToCSV();
	}
	else if (choice == 6) {
		moreInfo();
	}
	else if (choice == 7) {
		backupProfiles();
	}
	else if (choice == 8) {
		restoreProfiles();
	}
	else if (choice == 9) {
		cout << "Exitting...!\n";
	}

}


int main() {

	cout << "\t################################################\n";
	cout << "\t################################################\n";
	cout << "\t##                                            ##\n";
	cout << "\t##               WELCOME  TO                  ##\n";
	cout << "\t##                                            ##\n";
	cout << "\t##         SOLAR ESTIMATOR PROJECT            ##\n";
	cout << "\t##                                            ##\n";
	cout << "\t##                                            ##\n";
	cout << "\t################################################\n";
	cout << "\t################################################\n\n";


	while (true) {
		DisplayMainMenu();		
		
		char exit;
		do {
			cout << "Do you want to exit the program? (Y/N): \n";
			cin >> exit;
			if ((exit != 'Y') && (exit != 'y') && (exit != 'N') && (exit != 'n')) {
				cout << "Invalid Input! Please Try Again.\n";
			}

		} while ((exit != 'Y') && (exit != 'y') && (exit != 'N') && (exit != 'n'));

		// Skipping the loop
		if (exit == 'Y' || exit == 'y') {
			break;
		}
	}


	return 0;
}
