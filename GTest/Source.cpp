
#include "main.h"
#include <iostream>
#include <fstream>
#include <string>
#include "gtest/gtest.h"

using namespace std;
using namespace shapes;

void ContainerPattern(container *c)
{
	c->n = 6;
	c->cont = new list;
	list* cur = c->cont;
	cur->sh = new tetrahedron;
	cur->next = new list;
	((tetrahedron*)c->cont->sh)->t = TETRAHEDRON;
	((tetrahedron*)c->cont->sh)->side = 9;
	((tetrahedron*)c->cont->sh)->temp = 98;
	((tetrahedron*)c->cont->sh)->destiny = 354;
	cur = cur->next;

	cur->sh = new sphere;
	cur->next = new list;
	((sphere*)cur->sh)->t = SPHERE;
	((sphere*)cur->sh)->rad = 10;
	((sphere*)cur->sh)->temp = 100;
	((sphere*)cur->sh)->destiny = 500;

	cur = cur->next;
	cur->sh = new tetrahedron;
	cur->next = new list;
	((tetrahedron*)cur->sh)->t = TETRAHEDRON;
	((tetrahedron*)cur->sh)->side = 15;
	((tetrahedron*)cur->sh)->temp = 150;
	((tetrahedron*)cur->sh)->destiny = 1000;

	cur = cur->next;
	cur->sh = new parallelepiped;
	cur->next = new list;
	((parallelepiped*)cur->sh)->t = PARALLELEPIPED;
	((parallelepiped*)cur->sh)->e1 = 1;
	((parallelepiped*)cur->sh)->e2 = 10;
	((parallelepiped*)cur->sh)->e3 = 100;
	((parallelepiped*)cur->sh)->temp = 300;
	((parallelepiped*)cur->sh)->destiny = 1500;

	cur = cur->next;
	cur->sh = new sphere;
	cur->next = new list;
	((sphere*)cur->sh)->t = SPHERE;
	((sphere*)cur->sh)->rad = 25;
	((sphere*)cur->sh)->temp = 250;
	((sphere*)cur->sh)->destiny = 3000;

	cur = cur->next;
	cur->sh = new parallelepiped;
	cur->next = NULL;
	((parallelepiped*)cur->sh)->t = PARALLELEPIPED;
	((parallelepiped*)cur->sh)->e1 = 2;
	((parallelepiped*)cur->sh)->e2 = 20;
	((parallelepiped*)cur->sh)->e3 = 200;
	((parallelepiped*)cur->sh)->temp = 600;
	((parallelepiped*)cur->sh)->destiny = 5000;
}

void SortedContainerPattern(container *c)
{
	c->n = 6;
	c->cont = new list;
	list* cur = c->cont;
	cur->sh = new sphere;
	cur->next = new list;
	((sphere*)c->cont->sh)->t = SPHERE;
	((sphere*)cur->sh)->rad = 25;
	((sphere*)cur->sh)->temp = 250;
	((sphere*)cur->sh)->destiny = 3000;

	cur = cur->next;
	cur->sh = new parallelepiped;
	cur->next = new list;
	((parallelepiped*)cur->sh)->t = PARALLELEPIPED;
	((parallelepiped*)cur->sh)->e1 = 2;
	((parallelepiped*)cur->sh)->e2 = 20;
	((parallelepiped*)cur->sh)->e3 = 200;
	((parallelepiped*)cur->sh)->temp = 600;
	((parallelepiped*)cur->sh)->destiny = 5000;

	cur = cur->next;
	cur->sh = new sphere;
	cur->next = new list;
	((sphere*)cur->sh)->t = SPHERE;
	((sphere*)cur->sh)->rad = 10;
	((sphere*)cur->sh)->destiny = 500;
	((sphere*)cur->sh)->temp = 100;

	cur = cur->next;
	cur->sh = new parallelepiped;
	cur->next = new list;
	((parallelepiped*)cur->sh)->t = PARALLELEPIPED;
	((parallelepiped*)cur->sh)->e1 = 1;
	((parallelepiped*)cur->sh)->e2 = 10;
	((parallelepiped*)cur->sh)->e3 = 100;
	((parallelepiped*)cur->sh)->destiny = 1500;
	((parallelepiped*)cur->sh)->temp = 300;

	cur = cur->next;
	cur->sh = new tetrahedron;
	cur->next = new list;
	((tetrahedron*)cur->sh)->t = TETRAHEDRON;
	((tetrahedron*)cur->sh)->side = 15;
	((tetrahedron*)cur->sh)->destiny = 1000;
	((tetrahedron*)cur->sh)->temp = 150;

	cur = cur->next;
	cur->sh = new tetrahedron;
	cur->next = NULL;
	((tetrahedron*)cur->sh)->t = TETRAHEDRON;
	((tetrahedron*)cur->sh)->side = 9;
	((tetrahedron*)cur->sh)->destiny = 354;
	((tetrahedron*)cur->sh)->temp = 98;
}

bool CompareContainer(container *c1, container *c2)
{

	if (c1->n != c2->n)
		return false;
	else
	{
		int n = c1->n;
		for (int i = 0; i < n; i++)
		{
			if (c1->cont->sh->t == SPHERE && c2->cont->sh->t == SPHERE)
				if (((sphere*)c1->cont->sh)->rad != ((sphere*)c2->cont->sh)->rad)
					return false;
			if (c1->cont->sh->t == PARALLELEPIPED && c2->cont->sh->t == PARALLELEPIPED)
				if (((parallelepiped*)c1->cont->sh)->e1 != ((parallelepiped*)c2->cont->sh)->e1 || ((parallelepiped*)c1->cont->sh)->e2 != ((parallelepiped*)c2->cont->sh)->e2 || ((parallelepiped*)c1->cont->sh)->e3 != ((parallelepiped*)c2->cont->sh)->e3)
					return false;
			if (c1->cont->sh->t == TETRAHEDRON && c2->cont->sh->t == TETRAHEDRON)
				if (((tetrahedron*)c1->cont->sh)->side != ((tetrahedron*)c2->cont->sh)->side)
					return false;
			if ((c1->cont->sh->t != c2->cont->sh->t) || (c1->cont->sh->destiny != c2->cont->sh->destiny) || (c1->cont->sh->temp != c2->cont->sh->temp))
				return false;
			c1->cont = c1->cont->next;
			c2->cont = c2->cont->next;
		}
	}
	return true;
}

bool CompareFiles(ifstream &f1, ifstream &f2)
{
	string s1;
	string s2;
	int i = 0;
	while ((!f1.eof()) || (!f2.eof()))
	{
		getline(f1, s1);
		getline(f2, s2);
		if (s1 != s2)
		{
			cout << "String " << i + 1 << "don't match!\n" << s1 << "\n" << s2 << "\n";
			return false;
		}
		i += 1;
	}
	return true;
}

TEST(SphereTest, SphereInput)
{
	ifstream file("SphereInput.txt");
	sphere *actual = new sphere;
	actual->InData(file);
	
	EXPECT_TRUE(actual->rad == 5);
}

TEST(SphereTest, SphereOut)
{
	ofstream file("SphereOut.txt");
	sphere* s = new sphere;
	s->t = SPHERE;
	s->rad = 4;
	s->temp = 10;
	s->Out(file);
	file.close();
	ifstream actualFile("SphereOut.txt"), expectedFile("SphereOutPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(SphereTest, SphereVolume)
{
	sphere *actual = new sphere;
	actual->t = SPHERE;
	actual->rad = 5;
	float a = actual->Volume();
	float ExpectedVolume = 5 * 5 * 5 * 3.1415 * 4 / 3;
	EXPECT_TRUE(abs(a - ExpectedVolume) < 0.00001);
}

TEST(ParallelepipedTest, ParallelepipedIn)
{
	ifstream file("ParallelepipedIn.txt");
	parallelepiped *actual = new parallelepiped, *expected;
	expected = new parallelepiped;
	actual->InData(file);
	expected->t = PARALLELEPIPED;
	expected->e1 = 2;
	expected->e2 = 3;
	expected->e3 = 4;
	EXPECT_TRUE(actual->e1 == expected->e1);
	EXPECT_TRUE(actual->e2 == expected->e2);
	EXPECT_TRUE(actual->e3 == expected->e3);
}

TEST(ParallelepipedTest, ParallelepipedOut)
{
	ofstream file("ParallelepipedOut.txt");
	parallelepiped* p = new parallelepiped;
	p->t = PARALLELEPIPED;
	p->e1 = 4;
	p->e2 = 10;
	p->e3 = 8;
	p->temp = 5;
	p->Out(file);
	file.close();
	ifstream actualFile("ParallelepipedOut.txt"), expectedFile("ParallelepipedOutPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(ParallelepipedTest, ParallelepipedVolume)
{
	parallelepiped* actual = new parallelepiped;
	actual->t = PARALLELEPIPED;
	actual->e1 = 4;
	actual->e2 = 10;
	actual->e3 = 8;
	float ExpectedVolume = 4 * 10 * 8;
	EXPECT_TRUE(abs(actual->Volume() - ExpectedVolume) < 0.00001);
}

TEST(TetrahedronTest, TetrahedronIn)
{
	ifstream file("TetrahedronIn.txt");
	tetrahedron *actual = new tetrahedron, *expected;
	expected = new tetrahedron;
	actual->InData(file);
	expected->t = TETRAHEDRON;
	expected->side = 2;
	EXPECT_TRUE(actual->side == expected->side);
}

TEST(TetrahedronTest, TetrahedronOut)
{
	ofstream file("TetrahedronOut.txt");
	tetrahedron* t = new tetrahedron;
	t->t = TETRAHEDRON;
	t->side = 4;
	t->temp = 10;
	t->Out(file);
	file.close();
	ifstream actualFile("TetrahedronOut.txt"), expectedFile("TetrahedronOutPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(TetrahedronTest, TetrahedronVolume)
{
	tetrahedron* actual = new tetrahedron;
	actual->t = TETRAHEDRON;
	actual->side = 7;
	float ExpectedVolume = 7 * 7 * 7 * sqrt((double)2) / 12;
	EXPECT_TRUE(abs(actual->Volume() - ExpectedVolume) < 0.00001);
}

TEST(InputShapeTest, InputSphereInShape)
{
	ifstream file("InputSphereInShape.txt");
	shape *actual = new sphere;
	actual = actual->shape::In(file);
	shape *expected = new sphere;
	((sphere *)expected)->rad = 2;
	expected->t = SPHERE;
	expected->destiny = 650;
	expected->temp = 100;
	EXPECT_TRUE(((sphere *)expected)->rad == ((sphere *)actual)->rad);
	EXPECT_TRUE(expected->t == actual->t);
	EXPECT_TRUE(expected->destiny == actual->destiny);
	EXPECT_TRUE(expected->temp == actual->temp);
}

TEST(InputShapeTest, InputParallelepipedInShape)
{
	ifstream file("InputParallelepipedInShape.txt");
	shape *actual = new parallelepiped;
	actual = actual->shape::In(file);
	shape *expected = new parallelepiped;
	((parallelepiped *)expected)->e1 = 5;
	((parallelepiped *)expected)->e2 = 6;
	((parallelepiped *)expected)->e3 = 8;
	expected->t = PARALLELEPIPED;
	expected->destiny = 678;
	expected->temp = 90;
	EXPECT_TRUE(((parallelepiped *)expected)->e1 == ((parallelepiped *)actual)->e1);
	EXPECT_TRUE(((parallelepiped *)expected)->e2 == ((parallelepiped *)actual)->e2);
	EXPECT_TRUE(((parallelepiped *)expected)->e3 == ((parallelepiped *)actual)->e3);
	EXPECT_TRUE(expected->t == actual->t);
	EXPECT_TRUE(expected->destiny == actual->destiny);
	EXPECT_TRUE(expected->temp == actual->temp);
}

TEST(InputShapeTest, InputTetrahedronInShape)
{
	ifstream file("InputTetrahedronInShape.txt");
	shape *actual = new tetrahedron;
	actual = actual->shape::In(file);
	shape *expected = new tetrahedron;
	((tetrahedron *)expected)->side = 30;
	expected->t = TETRAHEDRON;
	expected->destiny = 654;
	expected->temp = 90;
	EXPECT_TRUE(((tetrahedron *)expected)->side == ((tetrahedron *)actual)->side);
	EXPECT_TRUE(expected->t == actual->t);
	EXPECT_TRUE(expected->destiny == actual->destiny);
	EXPECT_TRUE(expected->temp == actual->temp);
}

TEST(OutputShapeTest, ShapeParallelepipedOutput)
{
	ofstream file("ShapeParallelepipedOut.txt");
	shape *p = new parallelepiped;
	((parallelepiped*)p)->t = PARALLELEPIPED;
	((parallelepiped *)p)->e1 = 2;
	((parallelepiped *)p)->e2 = 3;
	((parallelepiped *)p)->e3 = 4;
	p->destiny = 50;
	p->temp = 600;
	p->Out(file);
	file.close();
	ifstream actualFile("ShapeParallelepipedOut.txt"), expectedFile("ShapeParallelepipedOutPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputShapeTest, ShapeSphereOut)
{
	ofstream file("ShapeSphereOut.txt");
	shape *s = new sphere;
	((sphere*)s)->t = SPHERE;
	((sphere *)s)->rad = 5;
	s->destiny = 20;
	s->temp = 700;
	s->Out(file);
	file.close();
	ifstream actualFile("ShapeSphereOut.txt"), expectedFile("ShapeSphereOutPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputShapeTest, ShapeTetrahedronOut)
{
	ofstream file("ShapeTetrahedronOut.txt");
	shape *s = new tetrahedron;
	((tetrahedron*)s)->t = TETRAHEDRON;
	((tetrahedron *)s)->side = 7;
	s->destiny = 50;
	s->temp = 6500;
	s->Out(file);
	file.close();
	ifstream actualFile("ShapeTetrahedronOut.txt"), expectedFile("ShapeTetrahedronOutPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(ShapeVolumeTest, ShapeSphereVolume)
{
	shape *actual = new sphere;
	((sphere*)actual)->t = SPHERE;
	((sphere*)actual)->rad = 5;
	float ExpectedVolume = 5 * 5 * 5 * 3.1415 * 4 / 3;
	EXPECT_TRUE(abs(actual->Volume() - ExpectedVolume) < 0.0001);
}

TEST(ShapeVolumeTest, ShapeparallelepipedVolume)
{
	shape *actual = new parallelepiped;
	((parallelepiped*)actual)->t = PARALLELEPIPED;
	((parallelepiped*)actual)->e1 = 8;
	((parallelepiped*)actual)->e2 = 6;
	((parallelepiped*)actual)->e3 = 10;
	
	float ExpectedVolume = 8 * 6 * 10;
	EXPECT_EQ(ExpectedVolume, actual->Volume());
}

TEST(ShapeVolumeTest, ShapeTetrahedronVolume)
{
	shape *actual = new tetrahedron;
	((tetrahedron*)actual)->t = TETRAHEDRON;
	((tetrahedron*)actual)->side = 7;
	
	float ExpectedVolume = 7 * 7 * 7 * sqrt((double)2) / 12;
	EXPECT_TRUE(abs(actual->Volume() - ExpectedVolume) < 0.0001);
}

TEST(ShapeCompareVolumeTest, CompareVolumeMore)
{
	shape *s1 = new tetrahedron;
	((tetrahedron*)s1)->t = TETRAHEDRON;
	((tetrahedron*)s1)->side = 3;

	shape *s2 = new parallelepiped;
	((parallelepiped*)s2)->t = PARALLELEPIPED;
	((parallelepiped*)s2)->e1 = 7;
	((parallelepiped*)s2)->e2 = 6;
	((parallelepiped*)s2)->e3 = 2;
	
	EXPECT_TRUE(s1->Compare(*s2));
}

TEST(ShapeCompareVolumeTest, CompareVolumeLess)
{
	shape *s1 = new tetrahedron;
	((tetrahedron*)s1)->t = TETRAHEDRON;
	((tetrahedron*)s1)->side = 9;

	shape *s2 = new parallelepiped;
	((parallelepiped*)s2)->t = PARALLELEPIPED;
	((parallelepiped*)s2)->e1 = 7;
	((parallelepiped*)s2)->e2 = 6;
	((parallelepiped*)s2)->e3 = 2;
	EXPECT_TRUE(!s1->Compare(*s2));
}


TEST(ShapeCompareVolumeTest, CompareVolumeEqually)
{
	shape *s = new parallelepiped;
	((parallelepiped*)s)->t = PARALLELEPIPED;
	((parallelepiped*)s)->e1 = 7;
	((parallelepiped*)s)->e2 = 6;
	((parallelepiped*)s)->e3 = 2;
	EXPECT_TRUE(!s->Compare(*s));
}

TEST(ClearContainerTest, ClearEmptyContainer)
{
	container *c = new container;
	c->cont = NULL;
	c->n = 0;

	c->~container();
	EXPECT_TRUE(c->cont == NULL);
	EXPECT_EQ(c->n, 0);
}

TEST(ClearContainerTest, ClearNonEmptyContainer)
{
	container *c = new container;
	c->cont = new list;
	c->cont->sh = NULL;

	c->n = 1;

	c->~container();
	EXPECT_TRUE(c->cont == NULL);
	EXPECT_EQ(c->n, 0);
}

TEST(InputContainerTest, OneSphereInContainer)
{
	ifstream file("OneSphereInContainer.txt");
	container *actual = new container;
	actual->n = 0;
	actual->cont = NULL;
	actual->In(file);
	container *expected = new container;
	expected->n = 1;
	expected->cont = new list;
	expected->cont->next = NULL;
	expected->cont->sh = new sphere;
	expected->cont->sh->t = SPHERE;
	expected->cont->sh->destiny = 650;
	expected->cont->sh->temp = 100;
	((sphere*)expected->cont->sh)->rad = 2;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, OneTetrahedronInContainer)
{
	ifstream file("OneTetrahedronInContainer.txt");
	container *actual = new container;
	actual->n = 0;
	actual->cont = NULL;
	actual->In(file);
	container *expected = new container;
	expected->n = 1;
	expected->cont = new list;
	expected->cont->next = NULL;
	expected->cont->sh = new tetrahedron;
	expected->cont->sh->t = TETRAHEDRON;
	expected->cont->sh->destiny = 650;
	expected->cont->sh->temp = 100;
	((tetrahedron*)expected->cont->sh)->side = 5;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, OneParallelepipedInContainer)
{
	ifstream file("OneParallelepipedInContainer.txt");
	container *actual = new container;
	actual->n = 0;
	actual->cont = NULL;
	actual->In(file);
	container *expected = new container;
	expected->n = 1;
	expected->cont = new list;
	expected->cont->next = NULL;
	expected->cont->sh = new parallelepiped;
	expected->cont->sh->t = PARALLELEPIPED;
	expected->cont->sh->destiny = 650;
	expected->cont->sh->temp = 100;
	((parallelepiped*)expected->cont->sh)->e1 = 5;
	((parallelepiped*)expected->cont->sh)->e2 = 6;
	((parallelepiped*)expected->cont->sh)->e3 = 7;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, NoElementsInContainer)
{
	ifstream file("NoElementsInContainer.txt");
	container *actual = new container;
	actual->cont = NULL;
	actual->n = 0;
	actual->In(file);

	container *expected = new container;
	expected->cont = NULL;
	expected->n = 0;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, SeveralElementsInContainer)
{
	ifstream file("SeveralElementsInContainer.txt");
	container *actual = new container;
	actual->cont = NULL;
	actual->n = 0;
	actual->In(file);

	container *expected = new container;
	ContainerPattern(expected);
	

	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(OutputContainerTest, SeveralElementsOutContainer)
{
	ofstream file("SeveralElementOutContainer.txt");
	container *actual = new container;
	ContainerPattern(actual);
	actual->Out(file);
	file.close();

	ifstream actualFile("SeveralElementOutContainer.txt"), expectedFile("SeveralElementOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OneSphereOutContainer)
{
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->sh = new sphere;
	actual->cont->sh->t = SPHERE;
	actual->cont->sh->destiny = 10.5;
	actual->cont->sh->temp = 25;
	((sphere*)actual->cont->sh)->rad = 25;

	ofstream file("OneSphereOutContainer.txt");
	actual->Out(file);
	file.close();

	ifstream actualFile("OneSphereOutContainer.txt"), expectedFile("OneSphereOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OneParallelepipedOutContainer)
{
	ofstream file("OneParallelepipedOutContainer.txt");
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->sh = new parallelepiped;
	actual->cont->sh->t = PARALLELEPIPED;
	actual->cont->sh->destiny = 15.5;
	actual->cont->sh->temp = 30;
	((parallelepiped*)actual->cont->sh)->e1 = 25;
	((parallelepiped*)actual->cont->sh)->e2 = 25;
	((parallelepiped*)actual->cont->sh)->e3 = 25;
	actual->Out(file);
	file.close();

	ifstream actualFile("OneParallelepipedOutContainer.txt"), expectedFile("OneParallelepipedOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OneTetrahedronOutContainer)
{
	ofstream file("OneTetrahedronOutContainer.txt");
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->sh = new tetrahedron;
	actual->cont->sh->t = TETRAHEDRON;
	actual->cont->sh->destiny = 15.5;
	actual->cont->sh->temp = 30;
	((tetrahedron*)actual->cont->sh)->side = 35;
	actual->Out(file);
	file.close();

	ifstream actualFile("OneTetrahedronOutContainer.txt"), expectedFile("OneTetrahedronOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, NoElementsOutContainer)
{
	ofstream file("NoElementsOutContainer.txt");
	container *actual = new container;
	actual->n = 0;
	actual->cont = NULL;

	actual->Out(file);
	file.close();

	ifstream actualFile("NoElementsOutContainer.txt"), expectedFile("NoElementsOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OnlySeveralSpheresOutContainer)
{
	ofstream file("OnlySeveralSpheresOutContainer.txt");
	container *actual = new container;
	ContainerPattern(actual);
	actual->OutSphere(file);
	file.close();

	ifstream actualFile("OnlySeveralSpheresOutContainer.txt"), expectedFile("OnlySeveralSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OnlySingleSphereOutContainer)
{
	ofstream file("OnlySingleSpheresOutContainer.txt");
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->sh = new sphere;
	actual->cont->sh->t = SPHERE;
	actual->cont->sh->destiny = 10.5;
	actual->cont->sh->temp = 25;
	((sphere*)actual->cont->sh)->rad = 25;
	actual->OutSphere(file);
	file.close();

	ifstream actualFile("OnlySingleSpheresOutContainer.txt"), expectedFile("OnlySingleSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, NoSpheresOutContainer)
{
	ofstream file("NoSpheresOutContainer.txt");
	container *actual = new container;
	actual->n = 0;
	actual->cont = NULL;
	actual->OutSphere(file);
	file.close();

	ifstream actualFile("NoSpheresOutContainer.txt"), expectedFile("NoSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(SortContainerTest, JustSortContainer)
{

	container *actual = new container;
	ContainerPattern(actual);
	actual->Sort();


	container *expected = new container;
	SortedContainerPattern(expected);

	ofstream f1("12.txt"), f2("14.txt");
	actual->Out(f1);
	expected->Out(f2);

	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, DoubleSortedContainer)
{
	container *actual = new container;
	ContainerPattern(actual);
	actual->Sort();
	actual->Sort();

	container *expected = new container;
	SortedContainerPattern(expected);

	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneSphereInContainer)
{
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->sh = new sphere;
	actual->cont->sh->t = SPHERE;
	actual->cont->sh->destiny = 10.5;
	actual->cont->sh->temp = 25;
	((sphere*)actual->cont->sh)->rad = 25;
	actual->Sort();

	container *expected = new container;
	expected->n = 1;
	expected->cont = new list;
	expected->cont->sh = new sphere;
	expected->cont->sh->t = SPHERE;
	expected->cont->sh->destiny = 10.5;
	expected->cont->sh->temp = 25;
	((sphere*)expected->cont->sh)->rad = 25;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneParallelepipedInContainer)
{
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->sh = new parallelepiped;
	actual->cont->sh->t = PARALLELEPIPED;
	actual->cont->sh->destiny = 10.5;
	actual->cont->sh->temp = 25;
	((parallelepiped*)actual->cont->sh)->e1 = 25;
	((parallelepiped*)actual->cont->sh)->e2 = 250;
	((parallelepiped*)actual->cont->sh)->e3 = 251;
	actual->Sort();

	container *expected = new container;
	expected->n = 1;
	expected->cont = new list;
	expected->cont->sh = new parallelepiped;
	expected->cont->sh->t = PARALLELEPIPED;
	expected->cont->sh->destiny = 10.5;
	expected->cont->sh->temp = 25;
	((parallelepiped*)expected->cont->sh)->e1 = 25;
	((parallelepiped*)expected->cont->sh)->e2 = 250;
	((parallelepiped*)expected->cont->sh)->e3 = 251;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneTetrahedronInContainer)
{
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->sh = new tetrahedron;
	actual->cont->sh->t = TETRAHEDRON;
	actual->cont->sh->destiny = 10.5;
	actual->cont->sh->temp = 25;
	((tetrahedron*)actual->cont->sh)->side = 25;
	actual->Sort();

	container *expected = new container;
	expected->n = 1;
	expected->cont = new list;
	expected->cont->sh = new tetrahedron;
	expected->cont->sh->t = TETRAHEDRON;
	expected->cont->sh->destiny = 10.5;
	expected->cont->sh->temp = 25;
	((tetrahedron*)expected->cont->sh)->side = 25;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, ReversedSortContainer)
{
	container *c = new container;
	c->n = 6;
	c->cont = new list;
	list* cur = c->cont;
	cur->sh = new tetrahedron;
	cur->next = new list;
	((tetrahedron*)c->cont->sh)->t = TETRAHEDRON;
	((tetrahedron*)c->cont->sh)->side = 9;
	((tetrahedron*)c->cont->sh)->destiny = 354;
	((tetrahedron*)c->cont->sh)->temp = 98;

	cur = cur->next;
	cur->sh = new tetrahedron;
	cur->next = new list;
	((tetrahedron*)cur->sh)->t = TETRAHEDRON;
	((tetrahedron*)cur->sh)->side = 15;
	((tetrahedron*)cur->sh)->destiny = 1000;
	((tetrahedron*)cur->sh)->temp = 150;

	cur = cur->next;
	cur->sh = new parallelepiped;
	cur->next = new list;
	((parallelepiped*)cur->sh)->t = PARALLELEPIPED;
	((parallelepiped*)cur->sh)->e1 = 1;
	((parallelepiped*)cur->sh)->e2 = 10;
	((parallelepiped*)cur->sh)->e3 = 100;
	((parallelepiped*)cur->sh)->destiny = 1500;
	((parallelepiped*)cur->sh)->temp = 300;

	cur = cur->next;
	cur->sh = new sphere;
	cur->next = new list;
	((sphere*)cur->sh)->t = SPHERE;
	((sphere*)cur->sh)->rad = 10;
	((sphere*)cur->sh)->destiny = 500;
	((sphere*)cur->sh)->temp = 100;

	cur = cur->next;
	cur->sh = new parallelepiped;
	cur->next = new list;
	((parallelepiped*)cur->sh)->t = PARALLELEPIPED;
	((parallelepiped*)cur->sh)->e1 = 2;
	((parallelepiped*)cur->sh)->e2 = 20;
	((parallelepiped*)cur->sh)->e3 = 200;
	((parallelepiped*)cur->sh)->destiny = 5000;
	((parallelepiped*)cur->sh)->temp = 600;

	cur = cur->next;
	cur->sh = new sphere;
	cur->next = NULL;
	((sphere*)cur->sh)->t = SPHERE;
	((sphere*)cur->sh)->rad = 25;
	((sphere*)cur->sh)->destiny = 3000;
	((sphere*)cur->sh)->temp = 250;

	c->Sort();

	container *expected = new container;
	SortedContainerPattern(expected);

	ofstream f1("12.txt"), f2("14.txt");
	c->Out(f1);
	expected->Out(f2);

	EXPECT_TRUE(CompareContainer(c, expected));
}

TEST(SortContainerTest, NothingInContainer)
{
	container *actual = new container;
	actual->n = 0;
	actual->cont = new list;
	actual->cont->next = NULL;
	actual->cont->sh = NULL;
	actual->Sort();

	container *expected = new container;
	expected->n = 0;
	expected->cont = new list;
	expected->cont->next = NULL;
	expected->cont->sh = NULL;

	EXPECT_TRUE(CompareContainer(actual, expected));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}