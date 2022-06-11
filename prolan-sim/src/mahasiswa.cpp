#include <iostream>
#include <vector>
#include "include/mahasiswa.hpp"


mahasiswa::mahasiswa(std::string id, std::string nama, int dd, int mm, int yy, 
				std::string nrp, std::string departemen,int tahunmasuk, std::string fakultas, std::vector<std::string> matkul)
		: person(id, nama, dd, mm, yy), nrp(nrp), departemen(departemen), tahunmasuk(tahunmasuk), fakultas(fakultas), matkul(matkul)
{
	this->ipk = 0.0;
	this->semesterke = 1;
	this->skslulus = 0;

	this->ips = std::vector<float>(14,0);
}

void mahasiswa::setSemester(int semesterke)
{
	this->semesterke = semesterke;
}

int mahasiswa::getSemester()
{
	return this->semesterke;
}

void mahasiswa::setSKSLulus(int skslulus)
{
	this->skslulus = skslulus;
}

int mahasiswa::getSKSLulus()
{
	return this->skslulus;
}

void mahasiswa::hitungIPK()
{
}

void mahasiswa::setIPS(int semester, float ips)
{
	// semester mulai dari 1
	if (semester < 15) {
		this->ips[semester-1] = ips;
		this->hitungIPK();
	}
}

float mahasiswa::getIPS(int semester)
{
	if (semester < 15)
		return this->ips[semester-1];

	return -1.0;
}

std::vector<float> mahasiswa::getAllIPS()
{
	return this->ips;
}

std::string mahasiswa::getNRP()
{
	return this->nrp;
}

void mahasiswa::setDepartemen(std::string departemen)
{
	this->departemen = departemen;
}

std::string mahasiswa::getDepartemen()
{
	return this->departemen;
}

int mahasiswa::getTahunMasuk()
{
	return this->tahunmasuk;
}


void mahasiswa::setFakultas(std::string fakultas)
{
	this->fakultas = fakultas;
}
std::string mahasiswa::getFakukltas()
{
	return this->fakultas;
}

void mahasiswa::setMatkul(std::string matkul)
{
	this->matkul.push_back(matkul);
}

std::vector<std::string> mahasiswa::getMatkul()
{
	return this->matkul;
}


