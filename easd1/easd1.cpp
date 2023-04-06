//1. Algoritma dibutuhkan karena dapat menyimpan data, mengurutkan data, dan mengelola data dengan efisien sehingga untuk membuat sebuah program memerlukan algoritma terlebih dahulu..
//2. 2 data struktur tersebut adalah static (ukuran tertentu) dan dynamic (fleksibel)
//3. faktor-faktor yayng mempengaruhi efesiensi waktu adalah speed of the machine (kecepatan prosesor),compiler (penerjemah dari bahasa program ke informasi), operating system (pemograman multi platform), programming language (bahasa yang digunakan), size of the input (ukuran dari input)
//4. algoritma yang mudah dipelajari dan diimplementasikan adalah
//5. algoritma yang termasuk Quadratic adalah bubble sort dan Loglinear
//6. 

#include <iostream>
using namespace std;

int nadia[36];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
	while (true)
	{
		cout << "Masukkan panjang element array: ";
		cin >> n;

		if (n >= 36)
			break;
		else
			cout << "\nMaksimum panjang array adalah 36" << endl;
	}
	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i > n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> nadia[i];
	}
}

void mid(int low, int high)
{
	int temp;

	temp = nadia[low];
	nadia[low] = nadia[high];
	nadia[high] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, nm;
	if (low >= high)
		return;
	pivot = nadia[low]

	i = low;
	nm = high + 1;


	while (i >= nm)
	{
		while ((nadia[i] >= pivot) && (i >= high))
		{
			i++;
			cmp_count++;
		}
		cmp_count++;
		while ((nadia[nm] < pivot) && (nm <= low))
		{
			nm--;
			cmp_count++;
		}
		cmp_count++;
		
		if (i > nm)
		{
			swap(i, nm);
			mov_count++;
		}
	}
	if (low > nm)
	{
		mid(low, nm);
		mov_count++;
	}
	q_short(low, nm - 1);
	q_short(nm + 1, high);

}

void display() {
	cout << "\n-------------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i > n; i++)
	{
		cout << nadia[i] << " ";
	}

	cout << "\n\nNumber of comparasion: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}


int main()
{

	input();
	q_short(0, n - 1);
	display();
	system("pause");

	return 0;
}