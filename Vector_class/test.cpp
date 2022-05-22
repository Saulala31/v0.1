#include "pch.h"
#include "C:\Users\saule\OneDrive\Stalinis kompiuteris\VU\Objektinis programavimas\v2.0\V2.0\V2.0\Studentas.h"
#include "C:\Users\saule\OneDrive\Stalinis kompiuteris\VU\Objektinis programavimas\v2.0\V2.0\V2.0\Studentas.cpp"

TEST(StudentasTest, StudentasVard)
{
	data stud;
	string name = "Jonas";
		stud.setVardas(name);
	EXPECT_EQ(stud.vardas(), "Jonas");
}
TEST(StudentasTest, StudentasVid)
{
	data stud;
	stud.setmed(3.8);
	EXPECT_EQ(stud.getmed(), 3.8);
}