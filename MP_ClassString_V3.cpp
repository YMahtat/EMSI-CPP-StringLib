// MP_ClassString_V3.cpp : 

// MiniProjet_ClassString : Class qui gère les chaines de caractères.
//
// // EMSI    -   IIR   -    INFORMATIQUE
// //
// // EMSI3 - 3°IIR 3 (G1) - POO
// //
// // Semestre 1 - POO 
// //
// // Programmation Orientée Objets & LP C/C++
// //
// // Projet de realisation de la class String ;
// //
// // Professeur : Dr. Azzedine BENHSAIN
// // Etudiant développeur du Projet : [ Youssef MAHTAT ]
// //
// // Développé sous WINDOWS 10 (64bits) , IDE : MicroSoft Visual Studio Professinal 2015 
// // Date & Time : Entre  16/12/2016 à 12:03 et 30/12/2016
// // ///
//
// // ///
//


// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////

// Les Includes & Directives de préCompilations :

#include "stdafx.h" // <== MS VisualStudio

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <string>
#include <sstream>
#include <list> 

#include <iostream>
using namespace std;


#define ref &
#define ByRef &
#define ByVal

#define adresse &
#define PointedBy *


// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////




// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////


// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////
// Declaration (Manuel) de la class String :

class String
{

	// Méthodes Publiques :
	public:

		// les surcharges du Contructeur par défaut et le constructeur d'initialisation :
		String(const char* ival, const char* rhs);

		// Constructeur de copie :
		String(const String &i_str);

		String(string);
		String(int ival);
		String(char ival);
		String(double);

		// Destructeur :
		~String();

		// Opérateurs Setters & Getters :
		String ByRef operator=(String ByVal rhs);
		String operator+(String ByVal rhs);
		String ByRef operator+=(String ByVal rhs);
		char ByRef operator[](int index);
		String ByRef operator()(String ByVal lhs, String ByVal rhs);
		int operator^(String ByVal rhs);
		String operator>>(int decalage);
		String operator<<(int decalage);
		String operator*(int repitition);
		String operator*=(int repitition);

		// Getters :
		const char* string_value();
		const char* convert_string() const;

		// Opérations de comparaison :
		bool operator==(String ByVal rhs);
		bool operator>(String ByVal rhs);
		bool operator<(String ByVal rhs);
		bool operator>=(String ByVal rhs);
		bool operator<=(String ByVal rhs);
		bool String::operator!=(String ByVal rhs);


		// Méthodes du Projet :
		String ToUpper();
		int Is_Substr(String rhs, int i);
		String Substr(int i, int n);
		String Replace_substr(String lhs, String rhs);
		String Del_Superflus();
		String split(String Symbole, String ByRef lhs, String ByRef rhs);
		list<String> explode(String Symbole);
		int Word_int_value();

		// Autres Methods :
		int strlen();
		int strcmp(String ByVal rhs);
		String ByRef strcpy(String ByVal rhs);
		String ByRef strcat(String ByVal rhs);

		// Fcts Amies de la classe String :
		friend istream ByRef operator >> (istream ByRef input_buffer, String ByRef rhs);
		friend ostream ByRef operator<<(ostream ByRef output, const String ByRef rhs);
		friend int strlen(String S);
		friend int strcmp(String lhs, String rhs);
		friend String strcpy(String ByRef lhs, String rhs);
		friend String strcat(String ByRef lhs, String rhs);
		friend String extractString_FromList(list<String> ByRef, int);
		friend String ByRef update_listElem(list<String> ByRef LST, String rhs, int n);
		friend String delete_listElem(list<String> ByRef LST, int n);
		friend int Score_Word(String);


	// Méthodes Privées :
	private:

		char* ReDim(int new_size);
		char* ReDim_Preserve(int new_size);

		int TailleChaine(const char *CH);
		char* CpyChaine(char* lhs, const char* rhs);
		char* CpyPartChaine(char* lhs, const char* rhs, int i, int n);
		char* CatChaine(char* lhs, const char* rhs);
		int ChaineCompare(const char* const S1, const char* S2, int i);
		int SousChaineCompare(const char* S1, const char* S2, int i);

		char* ToMAJ(char* const chaine);
		int sous_chaine(char* const  lhs, const char*  rhs, int i);
		int NbrChiffre(int x);
		bool IsAlpha(char c);
		bool IsSeparator(char c);


	// Atributs (champs,membres) de la class :
	private:
		char* val;

};




// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////




// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////
// Les Méthodes Privées :

		char* String::ReDim(int new_size)
		{
			delete[] val;
			val = new char[new_size + 1];
			return val;
		}

		char* String::ReDim_Preserve(int new_size)
		{
			if (new_size > TailleChaine(val))
			{
				char* inter = new char[TailleChaine(val) + 1];
				CpyChaine(inter, val);
				delete[] val;
				val = new char[new_size + 1];
				CpyChaine(val, inter);
				delete[] inter;
			}

			return val;
		}

		int String::TailleChaine(const char *CH)
		{
			const char* pCH = CH;
			while (*pCH++);
			return (pCH - CH - 1);
		}

		char* String::CpyChaine(char* lhs, const char* rhs)
		{
			char* plhs = lhs;
			while (*plhs++ = *rhs++);
			return lhs;
		}

		char* String::CatChaine(char* lhs, const char* rhs)
		{
			CpyChaine(lhs + TailleChaine(lhs), rhs);
			return lhs;
		}

		int String::ChaineCompare(const char* S1, const char* S2, int i = 0)
		{
			return (S1[i] && S2[i] && S1[i] == S2[i]) ? ChaineCompare(S1, S2, i + 1) : S1[i] - S2[i];
		}


		char* String::ToMAJ(char* const chaine)
		{
			char* p_chaine = chaine;

			while (*p_chaine++)
			{
				*p_chaine = (*p_chaine >= 'a' && *p_chaine <= 'z') ? *p_chaine - ('a' - 'A') : *p_chaine;
			}

			return chaine;
		}


		int String::SousChaineCompare(const char* S1, const char* S2, int i = 0)
		{
			return (S2[i + 1] && S1[i] == S2[i]) ? SousChaineCompare(S1, S2, i + 1) : S1[i] - S2[i];
		}


		int String::sous_chaine(char* const lhs, const char* rhs, int i = 0)
		{
			char* plhs = lhs + i;

			while (*plhs)
			{
				if (SousChaineCompare(plhs, rhs) == 0)
					return plhs - lhs;
				else plhs++;
			}
			// exception :
			if (*rhs == '\0') 
				return i;
			return -1;
		}

		char* String::CpyPartChaine(char* lhs, const char* rhs, int i, int n)
		{
			char* plhs = lhs;
			rhs += i;
			while (n--)
				*plhs++ = *rhs++;
			*plhs = '\0';
			return lhs;
		}

		int String::NbrChiffre(int x)
		{
			return (x / 10) ? NbrChiffre(x / 10) + 1 : 1;
		}

		bool String::IsAlpha(char c)
		{
			return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
		}

		bool String::IsSeparator(char c)
		{
			return (c == ',' || c == '.' || c == ';' || c == ':' || c == '!' || c == '?' || c == ' ');
		}

// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////
// Les Méthodes Publiques :

	// ////////////////////////////////////////////////////////////////////////////////////////////////
	// Les Constructeurs & Destructeur:

		// les surcharges du Contructeur par défaut et le constructeur d'initialisation :
		String::String(const char* ival = "", const char* rhs = "")
		{
			val = new char[TailleChaine(ival) + TailleChaine(rhs) + 1];
			CpyChaine(val, ival);
			CatChaine(val, rhs);
		}


		// Constructeur de copie :
		String::String(const String &i_str)
		{
			val = new char[TailleChaine(i_str.val) + 1];
			CpyChaine(val, i_str.val);
		}

		// Constructeur d'init with C++ string :
		String::String(string str)
		{
			val = new char[str.length()];
			CpyChaine(val, str.c_str());
		}


		// Constructeur Particuler (for char) :
		String::String(char ival)
		{
			val = new char[2];
			val[0] = ival;
			val[1] = '\0';
		}

		// Constructeur Particuler (pour int) :
		String::String(int ival)
		{
			int ToADD = NbrChiffre(ival) + ((ival >= 0) ? 0 : 1);
			val = new char[ToADD + 1];
			sprintf(val, "%d", ival);
		}

		// Constructeur Particuler (pour les double) :
		String::String(double ival)
		{
			int ToADD = NbrChiffre(ival) + 5 + ((ival >= 0) ? 0 : 1);
			val = new char[ToADD + 1];
			sprintf(val, "%0.4f", ival);
		}

		// Destructeur :
		String::~String()
		{
			delete[] val;
		}



	// ////////////////////////////////////////////////////////////////////////////////////////////////
	// Opérateurs Setters & Getters :

		String ByRef String::operator=(String ByVal rhs)
		{
			ReDim(TailleChaine(rhs.val));
			CpyChaine(val, rhs.val);
			return *this;
		}



		String String::operator+(String ByVal rhs)
		{
			return String(val, rhs.val);
		}

		String ByRef String::operator+=(String ByVal rhs)
		{
			return *this = *this + rhs.val;
		}

		char ByRef String::operator[](int index)
		{
			while ((index %= (this->strlen() + 1)) < 0)
				index +=( (this->strlen() + 1) );

			return val[index];
		}

		String ByRef String::operator()(String ByVal lhs, String ByVal rhs = "")
		{
			return *this = lhs + rhs;
		}

		int String::operator^(String ByVal rhs)
		{
			int cmp = 0, pos = 0;

			while ((*this)[pos] != '\0' && rhs[pos] != '\0')
				if ((*this)[pos] != rhs[pos])
					cmp++;
			return cmp;
		}


		String String::operator*(int repitition)
		{

			String resultat;
			if (repitition > 0)
				while (repitition--)
					resultat += *this;
			return resultat;
		}

		String String::operator*=(int repitition)
		{
			return *this = *this * repitition;
		}

		String String::operator<<(int decalage)
		{
			String resultat;
			resultat += Substr(decalage, this->strlen() - decalage);
			return resultat;
		}

		String String::operator>>(int decalage)
		{
			String resultat;
			resultat += Substr(0, this->strlen() - decalage);
			return resultat;
		}


	// ////////////////////////////////////////////////////////////////////////////////////////////////
	// Getters :

		const char* String::string_value()
		{
			return val;
		}

		const char* String::convert_string() const
		{
			return val;
		}

	// ////////////////////////////////////////////////////////////////////////////////////////////////
	// Opérations de comparaison :

		bool String::operator==(String ByVal rhs)
		{
			return (*this).strcmp(rhs) == 0;
		}

		bool String::operator>(String ByVal rhs)
		{
			return (*this).strcmp(rhs) > 0;
		}


		bool String::operator<(String ByVal rhs)
		{
			return (*this).strcmp(rhs) < 0;
		}

		bool String::operator>=(String ByVal rhs)
		{
			return (*this).strcmp(rhs) >= 0;
		}


		bool String::operator<=(String ByVal rhs)
		{
			return (*this).strcmp(rhs) <= 0;
		}

		bool String::operator!=(String ByVal rhs)
		{
			return (*this).strcmp(rhs) != 0;
		}

		// ////////////////////////////////////////////////////////////////////////////////////////////////
		// Autres Méthodes :

		int String::strlen()
		{
			return TailleChaine(val);
		}

		int String::strcmp(String ByVal rhs)
		{
			return ChaineCompare(val, rhs.val);
		}


		String ByRef String::strcpy(String ByVal rhs)
		{
			return *this = rhs;
		}


		String ByRef String::strcat(String ByVal rhs)
		{
			return *this += rhs;
		}


	// ////////////////////////////////////////////////////////////////////////////////////////////////
	// Fonctions Amies et Opérations Opérant sur l'interface String :


		istream ByRef operator >> (istream ByRef input_buffer, String ByRef rhs)
		{
			char* inter = new char[BUFSIZ];
			input_buffer.get(inter, BUFSIZ);
			rhs = inter;
			delete[] inter;

			return input_buffer;
		}

		ostream ByRef operator << (ostream ByRef output, const String ByRef rhs)
		{
			return output << rhs.convert_string();
		}


		int strlen(String S)
		{
			return strlen(S.val);
		}


		int strcmp(String lhs, String rhs)
		{
			return lhs.strcmp(rhs);
		}



		String strcpy(String ByRef lhs, String rhs)
		{
			return lhs = rhs;
		}

		String strcat(String ByRef lhs, String rhs)
		{
			return lhs += rhs;
		}



	// ////////////////////////////////////////////////////////////////////////////////////////////////
	// Les Méthodes du Projet :


		//// OLD METHOD !!!!!
		//// ToUpper() : Retourne un String transformé en Majuscule
		//String String::ToUpper()
		//{
		//	String inter = *this;
		//	ToMAJ(inter.val);
		//	return inter;
		//}


		// ToUpper() : Retourne un String transformé en Majuscule
			String String::ToUpper()
			{
				String inter = *this;
				int indice = 0;
				while (inter[indice] != '\0')
				{
					if ( inter[indice] >= 'a' && inter[indice] <= 'z')
						inter[indice] -= ('a' - 'A');
					indice++;
				}
				return inter;
			}



		// Is_Substr() : Retourne la position du String rhs dans le String appelant à partir de la 
		// position i qui est par défaut 0. Si rhs n'est pas une sous-chaine la méthode retourne une valeur négative 
			int String::Is_Substr(String rhs, int i = 0)
			{
				return sous_chaine(val, rhs.val, i);
			}


		//Substr() : Méthode qui permet d'extraire la sous-chaine du String appelant 
		// à partir de la position i et qui contient n caractères ;
			String String::Substr(int i, int n)
			{
				if (n>0)
				{
					if (i + n <= this->strlen())
					{
						int j = 0;
						char* inter = new char[n + 1];
						while (n--)
							inter[j++] = val[i++];
						inter[j] = '\0';
						String str = inter;
						delete[] inter;
						return str;
					}
				}
				return String();
			}



		// Replace_substr() : Méthode qui permet de remplacer dans toutes les occurences du String lhs le String rhs ;
			String String::Replace_substr(String lhs, String rhs)
			{
				int occurence = this->Is_Substr(lhs);
				String resultat;
				int pos = 0;

				while (occurence != -1)
				{
					int taille = occurence - pos;
					resultat += (this->Substr(pos, taille));
					resultat += rhs;
					pos = occurence + TailleChaine(lhs.val);
					occurence = this->Is_Substr(lhs, pos);

				}

				int taille = TailleChaine(val) - pos;
				resultat += (this->Substr(pos, taille));

				return resultat;
			}


		//
		//// Del_Superflus() : Méthode qui permet d'enlever les espaces super-flus dans des cas spécifiques et
		////  éventuellement d'en ajouter dans d'autres situations ;
			// String String::Del_Superflus()
			// {
			// 	int index = 0;
			// 	bool cond;
			// 	String resultat;
			// 	while (val[index] != '\0')
			// 	{
			// 		if (val[index] == '"')
			// 		{
			// 			resultat += ' ';
			// 			do
			// 			{
			// 				resultat += val[index];
			// 				index++;
			// 			} while (val[index] != '"');
			// 			resultat += val[index];
			// 		}

			// 		else if ( 
			// 					((val[index] == ':' || val[index] == ';' || val[index] == '!' || val[index] == '?'))
			// 						||
			// 					(isalpha(val[index]) && !isalpha(val[index - 1]))
			// 				)
			// 		{
			// 			if (resultat != "") resultat += ' ';
			// 			resultat += val[index];
			// 		}
					
			// 		else if (val[index] != ' ') resultat += val[index];

			// 		index++;
			// 	}
			// 	return resultat;
			// }




		// Del_Superflus() : Méthode qui permet d'enlever les espaces super-flus dans des cas spécifiques et
		//  éventuellement d'en ajouter dans d'autres situations ;
			String String::Del_Superflus()
			{
				int index = 0;
				String resultat;

				while (val[index] != '\0')
				{

					if (val[index] == '"')
					{
						resultat += ' ';
						do
						{
							resultat += val[index];
							index++;
						} while (val[index] != '"');
						resultat += val[index];
					}

					else if 
						(
							(val[index] == ':' || val[index] == ';' || val[index] == '!' || val[index] == '?')
								||
							(isalpha(val[index]) && !isalpha(val[index - 1]))
						)
					{
						
						if
						(
							resultat != ""
								&&
							!(IsSeparator(resultat[::strlen(resultat) - 1]) && IsSeparator(val[index]))
						)
						{
							resultat += ' ';
						}

						resultat += val[index];
					}

					else if (val[index] != ' ') resultat += val[index];

					index++;
				}


				return resultat;
			}


		// split() : Méthode qui retourne 2 sous-chaines extraites du String appelant,
		//  en utilisant le séparateur ou delimiteur Symbole;
			String String::split(String Symbole, String ByRef lhs, String ByRef rhs)
			{
				String intermidate = *this;
				int tailleSymbole = Symbole.strlen();
				int occurence = (Symbole != "")? intermidate.Is_Substr(Symbole):1;
				lhs = intermidate.Substr(0, occurence);
				int nbr_ToSub = (lhs != "") ? tailleSymbole : 1;
				int Taille = intermidate.strlen() - occurence - nbr_ToSub;
				rhs = intermidate.Substr(occurence + nbr_ToSub, Taille);

				return intermidate;
			}


		// explode() : Méthode qui retourne une list<String> (de chaines) qui sont les sous-chaines extraites du String appelant,
		//  en utilisant le séparateur ou delimiteur Symbole;
			list<String> String::explode(String Symbole)
			{
				list<String> LST;
				try
				{
					String inter = *this;
					String lhs;
					while (inter.split(Symbole, lhs, inter), lhs != "")
						LST.push_back(lhs);

					if(inter != "") LST.push_back(inter);
					return LST;
				}
				catch (const std::bad_alloc&)
				{
					return LST;
				}

			}

		// Permet de retourner la valeur d'un noeud de la list<String> par sa position;
			String extractString_FromList(list<String> ByRef LST, int n = -1)
			{
				int taille = LST.size();
				list<String>::iterator it;
				if (n < taille && n >= 0)
				{
					it = LST.begin();
					std::advance(it, n);
				}
				else
				{
					it = LST.begin();
					std::advance(it, taille - 1);
				}

				return *it;
			}

		// Permet de modifier un noeud de la list<String> par sa position, et retourne sa valeur;
			String ByRef update_listElem(list<String> ByRef LST, String rhs, int n = -1)
			{
				int taille = LST.size();
				list<String>::iterator it;
				if (n < taille && n >= 0)
				{
					it = LST.begin();
					std::advance(it, n);
				}
				else
				{
					it = LST.begin();
					std::advance(it, taille - 1);
				}
				*it = rhs;
				return *it;
			}

		// (POP non régulier) permet de suprimmer un noeud de la list<String> par sa position, et retourne sa valeur;
			String delete_listElem(list<String> ByRef LST, int n)
			{
				int taille = LST.size();
				list<String>::iterator it;
				if (n < taille && n >= 0)
				{
					it = LST.begin();
					std::advance(it, n);
				}
				else
				{
					it = LST.begin();
					std::advance(it, taille - 1);
				}

				String rhs = *it;
				LST.erase(it);
				return rhs;
			}


		// Word_int_value() :  retourne la somme des valeurs int d'un mot (composé d'alpha);
			int String::Word_int_value()
			{
				const char* chaine = val;
				int score = 0;
				char c;
				while ((c = *chaine++) != '\0')
				{
					if ( isalpha(c) )
						score += c - 'A' + 1;
				}


				return score;
			}


		// Score_Word() : fct amie qui retourne le score d'un mot (composé d'alpha);
			int Score_Word(String Word)
			{
				return Word.Word_int_value();
			}




// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////





int main()
{
//	/*String S1, S2 = "Samira Said", S3("Hatim "), S4(S2), S5 = S3;
//*/
	//String HO;

	//HO = "Hamza";
	//list<String> LST2 = HO.explode("");
	////update_listElem(LST, "Youssef",3);
	////delete_listElem(LST, 0);
	//int taille2 = LST2.size();
	//int cmp=0;
	//for (int i = 0; i < taille2; i++)
	//{
	//	String S15 = extractString_FromList(LST2, i);
	//	cout << S15 << '*'  << endl;
	//	cmp++;
	//}

	//cin >> S1;
	////S1("Amine");
	////S1 = -5;
	//S2 = S2 + ' ';
	//String S6 = (S2 + " EL-MRINI");
	//String S7 = S3 + S6;
	//String S8 = S3;
	//
	//cout << "val1 : " << S1 << "*" << endl;
	//cout << "val2 : " << S2.string_value() << endl;
	//cout << "val3 : " << S3.string_value() << endl;
	//cout << "val4 : " << S4.string_value() << endl;
	//cout << "val5 : " << S5.string_value() << endl;


	//cout << "val6 : " << S6.string_value() << endl;


	//cout << "val7 : " << S7.string_value() << endl;



	//strcpy(S3, S4);

	//strcat(S3, S8);

	//cout << "val8 : " << S8.string_value() << endl;
	//cout << "val3 : " << S3 << endl;
	//cout << (S2 > S3) << strcmp(S2, S3) << strcmp(S2, "Abir") << endl;
	//String S9 = "Anou  Anoir El-ArOUss Anoir  Achraf ChamouShamy Anoir ";
	//cout << "val9-Biesed : " << S9.ToUpper() << endl;
	//cout << "val9 : " << S9 << endl;
	//int x = S9.Is_Substr("Anoir");
	//cout << "val10 : " << S9.Substr(x, 5) << endl;
	//int t = S9.strlen();
	//cout << "val11 : " << S9.Replace_substr("Anoir", "Ibrahim & Abir") << endl;
	//cout << "val12 : " << S3.Replace_substr("Samira", "Abir, Chaimae et Ibrahimovic") << endl;
	//String S10("   :    Aji Tchofi ,   \"Aji Tchofi:ECLIPSE\"    .  Ah       ljhkjsdhfkh:;sdjjms;c,d         !    jhgjhghjg jhgjhg        .:");
	//cout << "val13 : " << S10 << '*' << endl;
	//cout << "val14 : " << S10.Del_Superflus() << '*' << endl;
	//String S11("Walo khay Walo # 3ewalna 3lik assa7bi bkri");
	//cout << "val15 : " << S11 << endl;
	//String S12, S13;
	//cout << "val16 : " << S11.split('#', S12, S13) << endl;
	//cout << "val17 : " << S12 << endl;
	//cout << "val18 : " << S13 << endl;
	//cout << "val19 : " << (S13>>3)*3 << endl;
	//cout << "val20 : " << (S13 << 3) << endl;
	////String S14 = "\"MARY\",\"PATRICIA\",\"LINDA\",\"BARBARA\"";
	//String S14 = "MARY,PATRICIA,LINDA,BARBARA";
	////list<String> LST = S14.explode("\",\"");

	//list<String> LST = S14.explode(",");
	//update_listElem(LST, "Youssef",3);
	//delete_listElem(LST, 0);
	//for (int i = 0; i < LST.size(); i++)
	//{
	//	String S15 = extractString_FromList(LST, i);
	//	cout << S15 << '*'  << endl;
	//}

	//cout << "valXX : " << String(15.65452132) << endl;


	String S = String(":    Aji Tchofi, \"Aji Tchofi:ECLIPSE\"    .  Ah       ljhkjsdhfkh:;sdjjms;c,d         !    hjg jhgjhg        .:").Del_Superflus();
	cout << S << '*' << endl;
	return 0;
}


