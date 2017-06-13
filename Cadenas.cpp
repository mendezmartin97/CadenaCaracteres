//============================================================================
// Name        : Cadena.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int length(string s)
{
   int i=0;
   while(s[i]!='\0')
   i++;

   return i;
}
int charCount(string s, char c)
{
   int i,h;
   i = h = 0;
   while(s[i]!='\0')
   {
      if(s[i]==c)
         h++;

      i++;
   }
   return h;
}
string substring(string s,int d, int h)//d inclusive - h noinclusive
{
   string sub;
   for(int i=d;i<h;i++)
      sub+=s[i];

   return sub;
}
string substring(string s, int d)//Retorna la subcadena comprendida entre d y el final
{
   string sub = substring(s,d,length(s));
   return sub;
}
int indexOf(string s, char c)
{
   int i=0;
   while(s[i]!='\0')
   {
      if(s[i]==c)
         return i;
      i++;
   }
   return -1;
}
int indexOf(string s,char c, int offSet)
{
   string sub = substring(s,offSet);
   int index = indexOf(sub,c);
   return index;
}
int indexOfN(string s,char c,int n)
{
   int acu=0;
   for(int i=0;i<n;i++)
      acu+=indexOf(s,c,acu)+1;

   return acu-1;
}
int pow(int x, int y)
{
   int z=1;
   for(int i=0;i<y;i++)
      z=z*x;
   return z;
}
int charToInt(char c)
{
 /*  if('A' <= c && c <= 'Z')//Esto es para cuando es stringToInt quier usar un hexa
      return c-'7';
      else
         return c-'0';
   */
   return ('A' <= c && c <= 'Z')?c-'7':c-'0';
}
char intToChar(int i)
{
   return i+'0';
}
int getDigit(int n, int i)
{
   int aux = n/(pow(10,i));
   aux=aux%10;
   return aux;
}
int digitCount(int i)
{
   int cont=0;
   while(i!=0)
   {
      i=i/10;
      cont++;
   }
   return cont;
}
string intToString(int i)
{
   bool b;
   string s="";
   //Funciona para enteros negativos
   i<0?b=true,i=abs(i):b=false;
   int h=digitCount(i);
   int aux;
   for(int g=0;g<h;g++)
   {
      aux=getDigit(i,g);
      s=intToChar(aux)+s;
   }
   return b?"-"+s:s;
}
int stringToInt(string s,int b)
{//Se puede pasar un numero en Hexa y la base 16 y lo resuelve gracias al charToInt
 //Ademas de que tambien calcula enteros negativos en el string
   int a,nro;
   bool f;
   a=nro=0;
   if(s[0]=='-')
      f=false;
   else
      f=true;

   if(f)
   {
      for(int i=0;i<length(s);i++)
      {
         nro+=(charToInt(s[i])* pow(b,(length(s)-1)-i));
      }
   }
   else
   {
      for(int i=1;i<length(s);i++)
      {
         nro+=(charToInt(s[i])* pow(b,(length(s)-1)-i));
      }
      nro*=-1;
   }

   return nro;
}
int stringToInt(string s)
{
   return stringToInt(s,10);
}
string charToString(char c)
{
   string s="_";
   s[0]=c;
   return s;
}
char stringToChar(string s)
{
   char c=s[0];
   return c;
}

string doubleToString(double d)
{//Utilizo presicion de dos decimales
   int parteEntera = (int)d;
   int parteDecimal = (d-parteEntera)*100;
   if(digitCount(parteDecimal)==1)
      return intToString(parteEntera)+".0"+intToString(parteDecimal);
   else
   return intToString(parteEntera)+"."+intToString(parteDecimal);
}
double stringToDouble(string s)
{//Devuelve un double de presicion 2
   bool b=true;
   string s1,s2;
   s1=s2="";
   int cont=0;
   for(int j=0;j<length(s);j++)
   {
      if(s[j]=='.')
      {
         b=false;
      }
      if(b)
         s1+=s[j];
      else
      {
         if(cont<2)
            s2+=s[j+1];
         cont++;
      }
   }
   int pEnt = stringToInt(s1);
   int pFrac = stringToInt(s2);
   double d=pEnt+(pFrac*0.01);
   return d;
}


bool isEmpty(string s)
{
   return length(s)==0?true:false;
}
bool contains(string s,char c)
{
      return indexOf(s,c)==-1?false:true;
}
string replace(string s, char oldChar, char newChar)
{
   int i=0;
   while(s[i]!='\0')
   {
      if(s[i]==oldChar)
         s[i]=newChar;
      i++;
   }
   return s;
}
string insertAt(string s, int pos, char c)
{
   return substring(s,0,pos)+c+substring(s,pos);
}
string removeAt(string s,int pos)
{
   return substring(s,0,pos)+substring(s,pos+1);
}
string ltrim(string s)
{
   string sub;
   int i=0;
   bool b=true;
   while(b)
   {
      if(s[i]!='_')//Para probar si funciona utilizo de caracter vacio el '_' e ingrese una palabra como "__hola" y me devolvio "hola"
        {sub=substring(s,i);
           b=false;
        }
      i++;
   }
   return sub;
}
string rtrim(string s)
{
   string sub;
   int i=length(s)-1;
   bool b=true;
   while(b)
   {
      if(s[i]!='_')//Para probar si funciona utilizo de caracter vacio el '_' e ingrese una palabra como "hola__" y me devolvio "hola"
        {sub=substring(s,0,i+1);
           b=false;
        }
      i--;
   }
   return sub;
}
string trim(string s)
{
   return rtrim(ltrim(s));
}
string replicate(int n,char c)
{
   string s="";
   for(int i=0;i<n;i++)
      s+=c;
   return s;
}
string spaces(int n)
{
   return replicate(n,'_');
}
string lpad(string s,int n,char c)
{  //Retorna una cadena identica a s pero de longitud n complementando
   //de ser necesario con caracteres c a la izquierda.
   return replicate(n-length(s),c)+s;
}
string rpad(string s,int n,char c)
{//return n>length(s)?(s+replicate(n-length(s),c)):s;
   return s+replicate(n-length(s),c);
}
string cpad(string s,int n,char c)
{
   int lon = length(s);//lo guardo en una variable para
   //que no haga reitereadas llamas a la funcion length.
   return lpad(rpad(s,((n-lon)/2)+lon,c),n,c);
}
bool isDigit(char c)
{
   return c>=48&&c<=57?true:false;
}
bool isLetter(char c)
{
   return (c>=65&&c<=90)||(c>=97&&c<=122)?true:false;
}
bool isUpperCase(char c)
{
   return (c>=65&&c<=90)?true:false;
}
bool isLowerCase(char c)
{
   return (c>=97&&c<=122)?true:false;
}
char toUpperCase(char c)
{
   return c-32;
}
char toLowerCase(char c)
{
   return c+32;
}
int tokenCount(string s,char sep)
{
   return s==""?0:charCount(s,sep)+1;
}
string getTokenAt(string s,char sep,int i)
{
   i++;
   string sub;
   int cant=tokenCount(s,sep);
   if(i==1)
      sub=substring(s,0,indexOf(s,sep));
   else
      {
         if(i==cant)
            sub=substring(s,indexOfN(s,sep,cant+1)+1);
         else
         {
          sub=substring(s,indexOfN(s,sep,i-1)+1,indexOfN(s,sep,i));
         }
      }
   return sub;
}
void addToken(string& s, char sep, string t)
{
   int cant=tokenCount(s,sep);
   cant==0?s=t:s=s+sep+t;
}
string removeTokenAt(string &s,char sep, int i)
{
   //i++;
   int cant=tokenCount(s,sep);
   string sub="";
   for(int j=0;j<cant;j++)
   {
      if(j!=i)
         addToken(sub,sep,getTokenAt(s,sep,j));
   }
   return sub;
}

void setTokenAt(string &s,char sep,string t,int i)
{
   int cant=tokenCount(s,sep);
   string sub="";
   for(int j=0;j<cant;j++)
   {
      if(j!=i)
         addToken(sub,sep,getTokenAt(s,sep,j));
      else
         addToken(sub,sep,t);
   }
   s=sub;
}
int findToken(string s,char sep,string t)
{
   int cant=tokenCount(s,sep);
   for(int i=0;i<cant;i++ )
   {
      if(getTokenAt(s,sep,i)==t)
      {
         return i;
      }
   }
   return -1;
}
struct Coll
{
   string s;
   char sep;
};
Coll collCreate(char sep='|')
{//Se hardcodea el separador en caso de que no me pase cual es al caracter '|'
   Coll ret;
   ret.s="";
   ret.sep=sep;
   return ret;
}
int collSize(Coll c)
{
   return tokenCount(c.s,c.sep);
}
void collRemoveAll(Coll &c)
{//Uso el create asi me crea uno vacio y con un sep hardcodeado
   c=collCreate();
}
void collRemoveAt(Coll &c,int p)
{
   c.s=removeTokenAt(c.s,c.sep,p);
}
void collAddString(Coll& coll, string s)
{
   addToken(coll.s,coll.sep,s);
}
void collSetStringAt(Coll &c,string s,int p)
{
   setTokenAt(c.s,c.sep,s,p);
}
string collGetStringAt(Coll c, int p)
{
   return getTokenAt(c.s,c.sep,p);
}
int collFindString(Coll c,string s)
{
   return findToken(c.s,c.sep,s);
}
void collAddInt(Coll& c,int i)
{
   addToken(c.s,c.sep,intToString(i));
}
void collSetIntAt(Coll& c,int i, int p)
{
   setTokenAt(c.s,c.sep,intToString(i),p);
}
int collGetIntAt(Coll c,int p)
{
   return stringToInt(collGetStringAt(c,p));
}
int collFindInt(Coll c,int i)
{
   return findToken(c.s,c.sep,intToString(i));
}
//****
void collAddDouble(Coll& c,double d)
{
   addToken(c.s,c.sep,doubleToString(d));
}
void collSetDoubleAt(Coll& c,double d, int p)
{
   setTokenAt(c.s,c.sep,doubleToString(d),p);
}
double collGetDoubleAt(Coll c,int p)
{
   return stringToDouble(collGetStringAt(c,p));
}

void collAddChar(Coll& c,char ch)
{
   addToken(c.s,c.sep,charToString(ch));
}
void collSetCharAt(Coll& c,char ch, int p)
{
   setTokenAt(c.s,c.sep,charToString(ch),p);
}
char collGetCharAt(Coll c,int p)
{
   return stringToChar(collGetStringAt(c,p));
}
int collFindChar(Coll c,char ch)
{
   return findToken(c.s,c.sep,charToString(ch));
}
template<typename T>
void collAdd(Coll& c, T t,string toString(T))//recibe una funcion toString que es la que pasa a string el dato t.
{
   addToken(c.s,c.sep,toString(t));
}
template<typename T>
void collSetAt(Coll& c,T t, int p, string tToString(T))
{
   setTokenAt(c.s,c.sep,tToString(t),p);
}
template<typename T>
T collGetAt(Coll c, int p, T stringToT(string))
{
   return stringToT(collGetStringAt(c,p));
}
template<typename T,typename K>
int collFind(Coll c, K k, int compare(T,K),T stringToT(string))
{
   bool b=true;
   int i=0;
   T t;
   int lon=collSize(c);
   while(b)
   {
      t=collGetAt(c,i,stringToT);
      if(compare(t,k)==0)
      {
         return i;
         b=false;
      }

      if(i>lon)
         b=false;
      i++;
   }
   return -1;
}
template <typename T>
void collSort(Coll &c,T t, int compare(T,T),T stringToT(string),string tToString(T))
{
   /* Descripcion: "Ordena la coleccion c segun el criterio
    * de comparacion que establece la funcion compare"
    * No me quedaba claro la descripcion
    * de lo que debia hacer esta funcion
    * pero yo hice que ordene siempre de menor a mayor
    * comparando con la funcion compare que me envien.
    *
    * */
   string s="";
   T aux;
   int cSize=collSize(c);
   int cantidadCambios=0;
   bool ordenado=false;
   while(!ordenado)
   {
      for(int i=0;i<cSize-1;i++)
      {
         if(compare(collGetAt(c,i,stringToT),collGetAt(c,i+1,stringToT))>0)
         {
            t=collGetAt(c,i+1,stringToT);
            aux=collGetAt(c,i,stringToT);
            collSetAt(c,t,i,tToString);
            collSetAt(c,aux,i+1,tToString);
            cantidadCambios++;
         }
      }
      if(cantidadCambios==0)
      {
         ordenado=true;
      }
      cantidadCambios=0;
   }
}

