#include <iostream>

class Car {
	std::string body;
	int enginePower;
	int wheelRadius;
	int numOfTransmissions;
	std::string typeOfTransmission;
public:
	void SetBody(std::string body) {
		this->body = body;
	}
	std::string GetBody() {
		return body;
	}
	void SetEnginePower(int enginePower){
		this->enginePower = enginePower;
	}
	int GetEnginePower() {
		return enginePower;
	}
	void SetWheelRadius(int wheelRadius) {
		this->wheelRadius = wheelRadius;
	}
	int GetWheelRadius() {
		return wheelRadius;
	}
	void SetNumOfTransmissions(int numOfTransmissions) {
		this->numOfTransmissions = numOfTransmissions;
	}
	int GetNumOfTransmissions() {
		return numOfTransmissions;
	}
	void SetTypeOfTransmission(std::string typeOfTransmission) {
		this->typeOfTransmission = typeOfTransmission;
	}
	std::string GetTypeOfTransmission() {
		return typeOfTransmission;
	}
	void ShowCar() {
		std::cout << "\tA new car:\nBody type is " << body << "\nEngine power: " << enginePower << "\nWheel Radius: " << wheelRadius
			<< "\nGearbox:\n\t" << "Number of Transmissions: " << numOfTransmissions << "\n\tTransmission Type: " << typeOfTransmission << std::endl;
	}
};

class CarFactory abstract {
protected:
	Car car;
public:
	Car GetCar() {
		return car;
	}
	virtual void BuildBody() abstract;
	virtual void BuildEngine() abstract;
	virtual void BuildWheel() abstract;
	virtual void BuildGearbox() abstract;
};

class DaewooLanosFactory : public CarFactory {
public:
	void BuildBody() override {
		car.SetBody("Sedan");
	};
	void BuildEngine() {
		car.SetEnginePower(98);
	};
	void BuildWheel() {
		car.SetWheelRadius(13);
	};
	void BuildGearbox() {
		car.SetNumOfTransmissions(5);
		car.SetTypeOfTransmission("Manual");
	};
};

class FordProbeFactory : public CarFactory {
public:
	void BuildBody() override {
		car.SetBody("Coupe");
	};
	void BuildEngine() {
		car.SetEnginePower(160);
	};
	void BuildWheel() {
		car.SetWheelRadius(14);
	};
	void BuildGearbox() {
		car.SetNumOfTransmissions(4);
		car.SetTypeOfTransmission("Auto");
	};
};

class UAZPatriotFactory : public CarFactory {
public:
	void BuildBody() override {
		car.SetBody("Universal");
	};
	void BuildEngine() {
		car.SetEnginePower(120);
	};
	void BuildWheel() {
		car.SetWheelRadius(16);
	};
	void BuildGearbox() {
		car.SetNumOfTransmissions(4);
		car.SetTypeOfTransmission("Manual");
	};
};

class HyundaiGetzFactory : public CarFactory {
public:
	void BuildBody() override {
		car.SetBody("Hatchback");
	};
	void BuildEngine() {
		car.SetEnginePower(66);
	};
	void BuildWheel() {
		car.SetWheelRadius(13);
	};
	void BuildGearbox() {
		car.SetNumOfTransmissions(4);
		car.SetTypeOfTransmission("Auto");
	};
};

class Shop {
	CarFactory* carFactory;
public:
	void SetCarFactory(CarFactory* carFactory) {
		this->carFactory = carFactory;
	}
	Car GetCar() {
		return carFactory->GetCar();
	}
	void ConstructCar() {
		carFactory->BuildBody();
		carFactory->BuildEngine();
		carFactory->BuildWheel();
		carFactory->BuildGearbox();
	}
};

void Client(CarFactory* carFactory) {
	Shop shop;
	shop.SetCarFactory(carFactory);
	shop.ConstructCar();
	Car car = shop.GetCar();
	car.ShowCar();
}

int main() {

	CarFactory* carFactory = new DaewooLanosFactory();
	Client(carFactory);
	delete carFactory;

	carFactory = new UAZPatriotFactory();
	Client(carFactory);
	delete carFactory;

	return 0;
}