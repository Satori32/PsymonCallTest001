#include <iostream>
#include <string>
#include <memory>
#include <random>
#include <ctime>
#include <cstdlib>

#define interface struct

#define Moning 1
#define Evenning 2
#define Neen 5
#define Night 3
#define Deep 4

interface I_IO_Base
{
	virtual const std::string Read()=0;
	virtual void Write(const std::string&)=0;
};

interface INameable
{
protected:
	std::string Name = "INameable.";
};

interface IAffili
{
protected:
	std::string Affili = "No Affiliation.";
};

interface IConjection
{
	virtual void Conjection() = 0;
protected:
	//std::string Conjection = "Conjection!";
};

interface IConnectable
{
	virtual bool Connect(const std::string&) = 0;
	virtual void DisConnect() = 0;
};

interface ClassPsymon : public I_IO_Base, INameable, IAffili, IConjection, IConnectable{
	virtual bool Connect(const std::string&) = 0;
	virtual void DisConnect() = 0;
	virtual const std::string Read() = 0;
	virtual void Write(const std::string&) = 0;
	virtual void Conjection()=0;
};

__pragma(warning(disable:4996))

namespace PsymonCall {
	void Send(int N, std::string Call) {
		std::cout <<"Call the " << N << " is to " << Call << std::endl;
	}
	std::string Get(int N) {
		std::cout << "it getting..." << std::endl;
		std::minstd_rand L((unsigned int)std::time(nullptr));
		std::uniform_real<double> U(0, 1);

		return U(L) >= 0.5 ? "Succsess!" : "Fail!";
	}
	void Show(std::string show) {
		std::cout << "Show it :" << show << std::endl;
	}
	void Show(int N) {
		std::cout << "Show it :" << N << std::endl;
	}
	int Seed() {
		return 16;
	}
}

class Psymon : public ClassPsymon {
public:
	bool Connect(const std::string& PC) {
		PsymonCall::Send(PsymonCall::Seed(), "I want to Connect at " + PC + " Is this?");
		S = PsymonCall::Seed();
		return PsymonCall::Get(16) == "Succsess!" ? true : false;
	}
	void DisConnect(){//i am under hand chain.
		PsymonCall::Send(S, "I Try DisConnect. thank you.");
		auto R = PsymonCall::Get(S);
		PsymonCall::Show(R);
		return;
	}

	const std::string Read() {
		auto R = rand() % 10;
		PsymonCall::Show(R);
		return R > 4 ? "it Readable!" : "not Readable!";
	}

	void Write(const std::string& T) {
		PsymonCall::Send(S, "Send:" + T + " Is This?" );
		X = PsymonCall::Get(S);
		this->Conjection();

		return;
	}

	void Conjection() {
		PsymonCall::Show("Conjection!");
		PsymonCall::Show(rand());
		PsymonCall::Show(X);

		return;
	}

	int Number() {
		return (rand() & 17)>=8? S:rand();
	}
	std::string String() {
		return "The String!";
	}

private:
	int S = -1;
	bool IsConnect = false;
	std::string X="None.";
};

bool WakeUp(Psymon* P, const std::string& Text) {
	PsymonCall::Send(Moning, "I am want to WakeUP to the bet.");
	std::string R = "";
	PsymonCall::Show(R = PsymonCall::Get(Moning));
	P->Write("WakeUP!!!!!");
	auto A = P->Read();
	bool b = R == "Succsess!";

	P->Conjection();

	if (P->Number()) {
		std::cout << "I wake Up. Say:" << Text << std::endl;
	}
	else {
		std::cout << "Mamunia... mamunia...  ..."<<std::endl;
	}

	return b;
}

void Eat(Psymon* P, const std::string& Text) {
	PsymonCall::Send(Moning, "I want to eat BrakeFirst");
	std::string R = "";
	PsymonCall::Show(R=PsymonCall::Get(Moning));
	if (R == "Succsess!") {
		P->Write("We can eat some it.");
	}
	else {
		PsymonCall::Send(Moning, "I nothing to some. leave.");
		return;
	}

	std::cout << "I eat. say:" << Text << std::endl;
	for (int i = 0; i < 16; i++) {
		std::cout << P->Read() << std::endl;
		P->Write("How taste.");
		P->Conjection();
		PsymonCall::Send(Moning, P->String());
	}

	P->Conjection();
	std::cout << P->String() << std::endl;

	std::cout << "Holy kill." << std::endl;
	PsymonCall::Send(Moning, "Holy kill. the end the eat one.");

	return;


}


int main() {
	/** /
	Psymon Psy=Psymon();
	auto R = Psy.Connect("Hello. I try go to School. Are you Allow?");
	auto S = Psy.Number();
	/**/
	std::shared_ptr<Psymon> Psy = std::make_shared<Psymon>();
	auto R = Psy->Connect("Hello. I try go to School. Are you Allow?");
	auto S = Psy->Number();
	if (!R) {
		PsymonCall::Send(S,"I leave.");
		std::cout << "Miss Connect!" << std::endl;
	}

	WakeUp(Psy.get(), "おはようございます！");
	Eat(Psy.get(), "いただきます！！");

	/////////////////////////////////////

	PsymonCall::Send(PsymonCall::Seed(), "Auther is over the writing. over.");
	std::cout << "うわー、世界は広いなー。" << std::endl;
	Psy->Conjection();

	/////////////////////////////////////

	std::cout << "application is end :" << PsymonCall::Get(PsymonCall::Seed()) << std::endl;

	return 0;
}