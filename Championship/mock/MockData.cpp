/*
 * MockData.cpp
 *
 *  Created on: 20/04/2021
 *      Author: pbs
 */

#include "MockData.h"

#include "DuplicatedDataException.h"

Date MockData::genDate(){
	int day = 1 + (rand() % 27);
	int month = 1 + (rand() % 12);
	int year = 1970 + (rand() % 40);
	Date dt(day,month,year);
	return dt;
}

void  MockData::insertSubjects(SubjectContainer& container){
	for (size_t  i = 0; i < this->name_subjects.size();i++){
		Subject obj(this->initial_subjects[i],this->name_subjects[i]);
		try{
			container.add(obj);
		}catch(DuplicatedDataException& e){
			//do nothing
		}
	}
}

void  MockData::insertStudents(StudentContainer& container){
	for (size_t i = 0; i < name_students.size();i++){
		Date dt = genDate();
		Student obj(name_students[i],dt);
		container.add(obj);
	}
}

void  MockData::insertInstructors(InstructorContainer& container){
	for (size_t i = 0; i < name_profs.size();i++){
		Instructor obj(initial_profs[i],name_profs[i]);
		try{
			container.add(obj);
		}catch(DuplicatedDataException& e){
			//do nothing
		}
	}
}

Subject * MockData:: getRandomSubject(SubjectContainer& subjects){
	list<Subject> listSubject = subjects.getAll();
	list<Subject>::iterator it = listSubject.begin();
	int is = rand() % listSubject.size();
	for(int i = 0; i < is; i++){
		it++;
	}
	//it = it + is;
	string initials = it->getInitials();
	Subject * ptr = subjects.get(initials);
	return ptr;
}
void  MockData::insertEnrolls(StudentContainer& students, SubjectContainer& subjects, EnrollContainer & container){
	list<Student> listStudent = students.getAll();
	for(list<Student>::iterator it = listStudent.begin(); it != listStudent.end(); ++it){
		Student * student =  students.get(it->getNumber());
		int n = 1 + rand() % ENROLLS_NR;
		for(int i = 0; i < n; i++){
			Subject * subject = getRandomSubject(subjects);
			int grade = 10 + rand() % 11;
			try{
				jogo enroll(grade, subject, student);
				container.add(enroll);
			}catch (DuplicatedDataException& e){
			}/*
			catch (...) {
			  std:cout << "Cacth anything";
			}*/
		}
	}
}

void  MockData::insertLectures(SubjectContainer & subjects, InstructorContainer & instructors ){
	list<Instructor> listInstructor = instructors.getAll();
	for (list<Instructor>::iterator it=listInstructor.begin(); it != listInstructor.end(); ++it){
		Instructor * ptr = instructors.get(it->getInitials());
		LectureContainer& container = ptr->getLectures();
		int n = 1 + rand() % LECTURES_NR;
		for(int i = 0; i < n; i++){
			Subject * subject = getRandomSubject(subjects);
			try{
				Lecture lecture(subject);
				container.add(lecture);
			}catch (DuplicatedDataException& e){
			}
		}
	}
}

void  MockData::generateData(School& school){
	srand (time(NULL));
	insertSubjects(school.getSubjectContainer());
	insertStudents(school.getStudentContainer());
	insertInstructors(school.getInstructorContainer());
	insertEnrolls(school.getStudentContainer(), school.getSubjectContainer(),school.getEnrollContainer());
	insertLectures( school.getSubjectContainer(), school.getInstructorContainer());



}

