/*
 * MockData.cpp
 *
 *  Created on: 19/04/2021
 *      Author: pbs
 */

#include <time.h>
#include<string>
#include<vector>

#include "School.h"

using namespace std;

class MockData{
private:
	const int ENROLLS_NR = 5;
	const int LECTURES_NR = 5;
	const vector<string> name_profs = {"Abrilina Décima Nona Caçapavana Piratininga de Almeida","Acheropita Papazone","Adalgamir Marge","Adegesto Pataca","Adoração Arabites","Aeronauta Barata","Agrícola Beterraba Areia","Agrícola da Terra Fonseca","Alce Barbuda","Aldegunda Carames More","Aleluia Sarango","Alfredo Prazeirozo Texugueiro","Alma de Vera","Amado Amoroso","Amável Pinto","Amazonas Rio do Brasil Pimpão","América do Sul Brasil de Santana","Amin Amou Amado","Amor de Deus Rosales Brasil","Anatalino Reguete","Antônio Americano do Brasil Mineiro","Antonio Buceta Agudim","Antonio Camisão","Antonio Dodói","Antonio Manso Pacífico de Oliveira Sossegado","Antonio Melhorança","Antônio Morrendo das Dores","Antonio Noites e Dias","Antônio P. Testa","Antonio Pechincha","Antônio Querido Fracasso","Antonio Treze de Junho de Mil Novecentos e Dezessete","Antônio Veado Prematuro","Apurinã da Floresta Brasileira","Araci do Precioso Sangue","Argentino Argenta","Aricléia Café Chá","Armando Nascimento de Jesus","Arquiteclínio Petrocoquínio de Andrade","Asteróide Silverio","Ava Gina","Bananéia Oliveira de Deus","Bandeirante do Brasil Paulistano","Barrigudinha Seleida","Bende Sande Branquinho Maracajá","Benedito Autor da Purificação","Benedito Camurça Aveludado","Benedito Frôscolo Jovino de Almeida Aimbaré Militão de Souza","Baruel de Itaparica Boré Fomi de Tucunduvá","Benigna Jarra"};
	const vector<string> initial_profs = {"ADNA","AAPP","ARME","AOPC","AOAS","AABA","ABAA","ATFA","AEBA","ACME","AASO","APTO","AAVA","AOAO","ALPO","ARBP","ASBS","AAAO","ADRB","AORE","AABM","ABAM","AOCO","AODI","AMPS","AMRA","AMDS","ANDS","APTA","AOPA","AQFO","AMND","AVPO","AFBA","APSE","AOAA","ACCA","ANJS","APAE","AESO","AAGA","BODS","BBPO","BASA","BSBM","BAPO","BCAO","BFJA","BIBT","BAJA"};
	const vector<string> name_students = {"Benvindo Viola","Bispo de Paris","Bizarro Assada","Boaventura Torrada","Bom Filho Persegonha","Brandamente Brasil","Brasil Washington C. A. Júnior","Brígida de Samora Mora","Belderagas Piruégas de","Alfim Cerqueira Borges Cabral","Bucetildes","Cafiaspirina Cruz","Capote Valente e Marimbondo da Trindade","Caius Marcius Africanus","Carabino Tiro Certo","Carlos Alberto Santíssimo Sacramento","Cantinho da Vila Alencar da Corte Real Sampaio","Carneiro de Souza e Faro","Caso Raro Yamada","Céu Azul do Sol Poente","Chananeco Vargas da Silva","Chevrolet da Silva Ford","Cincero do Nascimento","Cinconegue Washington Matos","Clarisbadeu Braz da Silva","Colapso Cardíaco da Silva","Comigo é Nove na Garrucha Trouxada","Confessoura Dornelles","Crisoprasso Compasso","Danúbio Tarada Duarte","Esdras Esdron Eustaquio Obirapitanga","Esparadrapo Clemente de Sá","Espere em Deus Mateus","Estácio Ponta Fina Amolador","Éter Sulfúrico Amazonino Rios","Excelsa Teresinha do Menino Jesus da Costa e Silva","Faraó do Egito Sousa","Fedir Lenho","Felicidade do Lar Brasileiro","Finólila Piaubilina","Flávio Cavalcante Rei da Televisão","Francisco Notório Milhão","Francisco Zebedeu Sanguessuga","Francisoreia Doroteia Dorida","Fridundino Eulâmpio","Gigle Catabriga","Graciosa Rodela D'alho","Heubler Janota","Hidráulico Oliveira","Himineu Casamenticio das Dores Conjugais","Holofontina Fufucas","Homem Bom da Cunha Souto Maior","Horinando Pedroso Ramos","Hugo Madeira de Lei Aroeiro","Hypotenusa Pereira","Ilegível Inilegível","Inocêncio Coitadinho","Isabel Defensora de Jesus","Izabel Rainha de Portugal","Janeiro Fevereiro de Março Abril","João Bispo de Roma","João Cara de José","João Cólica","João da Mesma Data","João de Deus Fundador do Colto","João Meias de Golveias","João Pensa Bem","João Sem Sobrenome","Joaquim Pinto Molhadinho","José Amâncio e Seus Trinta e Nove","José Casou de Calças Curtas","José Catarrinho","José Machuca","José Maria Guardanapo","José Padre Nosso","José Teodoro Pinto Tapado","José Xixi","Jovelina Ó Rosa Cheirosa","Jotacá Dois Mil e Um Juana Mula","Júlio Santos Pé-Curto","Justiça Maria de Jesus","Lança Perfume Rodometálico de Andrade","Leão Rolando Pedreira","Leda Prazeres Amante","Letsgo Daqui (let's go)","Liberdade Igualdade","Fraternidade Nova York Rocha","Libertino Africano Nobre","Lindulfo Celidonio Calafange de Tefé","Lynildes Carapunfada Dores Fígado","Magnésia Bisurada do Patrocínio","Manganês Manganésfero Nacional","Manolo Porras y Porras","Manoel de Hora Pontual","Manoel Sovaco de Gambar","Manuel Sola de Sá Pato","Manuelina Terebentina","Capitulina de Jesus Amor Divino","Marciano Verdinho das Antenas Longas","Maria Constança Dores Pança","Maria Cristina do Pinto","Magro Maria da Cruz Rachadinho","Maria da Segunda Distração","Maria de Seu Pereira","Maria Felicidade","Maria Humilde","Maria Máquina","Maria Panela","Maria Passa Cantando","Maria Privada de Jesus","Maria Tributina Prostituta Cataerva","Maria-você-me-mata","Mário de Seu Pereira","Meirelaz Assunção","Mijardina Pinto","Mimaré Índio Brazileiro de Campos","Ministéio Salgado","Naida Navinda Navolta Pereira","Napoleão Estado do Pernambuco","Napoleão Sem Medo e Sem Mácula","Natal Carnaval","Natanael Gosmoguete de Souza","Necrotério Pereira da Silva","Novelo Fedelo","Oceano Atlântico Linhares","Olinda Barba de Jesus","Orlando Modesto Pinto","Orquerio Cassapietra","Otávio Bundasseca","Pacífico Armando Guerra","Padre Filho do Espírito Santo Amém","Pália Pélia Pólia Púlia dos Guimarães Peixoto","Paranahyba Pirapitinga Santana","Penha Pedrinha Bonitinha da Silva"};
	const vector<string> name_subjects ={" Álgebra", "Algoritmia e Programação", "Circuitos Elétricos e Eletrónicos", " Matemática I", "Projeto de Engenharia", "Sistemas Digitais","Arquitetura de Computadores", "Fundamentos de Desenvolvimento de Software", "Fundamentos de Telecomunicações", "Matemática II", " Microprocessadores", "Sistemas de Eletrónica Analógica"};
	const vector<string> initial_subjects = {"ALGB", "APROG", "CIRCE", "MATE1", "PROJE", "SISDIG", "ARQCP", "FSOFT", "FTELC", "MATE2", "MCROP", "SISEA"};

	Date genDate();

	void insertSubjects(SubjectContainer& container);

	void insertStudents(StudentContainer& container);
	void insertInstructors(InstructorContainer& container);
	Subject * getRandomSubject(SubjectContainer& subjects);
	void  insertEnrolls(StudentContainer& students, SubjectContainer& subjects, EnrollContainer & container);
	void  insertLectures(SubjectContainer & subjects, InstructorContainer & instructors );
public:
	void generateData(School& school);

};


