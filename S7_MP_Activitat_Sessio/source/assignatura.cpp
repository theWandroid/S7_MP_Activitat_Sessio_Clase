#include "assignatura.h"

Assignatura::Assignatura(string nom, string nomProfessor, string mailProfessor, string despatx,
    int nEstudiants, 
    string estudiants[MAX_ESTUDIANTS][2]) : m_professorAssignatura(nomProfessor, mailProfessor, despatx)
{
    m_nom = nom;
    m_nEstudiants = nEstudiants;
    for (int i = 0; i < m_nEstudiants; i++)
    {
        m_estudiantsMatriculats[i].inicialitza(estudiants[i][0], estudiants[i][1]);
    }
}

int cercaEstudiant(Estudiant estudiants[], int nEstudiants, string niu) 
{
    bool trobat = false;
    int i = 0;
    while (!trobat && (i < nEstudiants))
    {
        if (estudiants[i].getNiu() == niu)
            trobat = true;
        else
            i++;
    }
    if (trobat)
        return i;
    else
        return -1;

}

void Assignatura::afegeixEstudiant(string nom, string niu) 
{
    m_nEstudiants++;
    m_estudiantsMatriculats[m_nEstudiants].inicialitza(m_estudiantsMatriculats[m_nEstudiants][0], m_estudiantsMatriculats[m_nEstudiants][1]);
    m_estudiantsMatriculats[m_nEstudiants][0] = nom;
    m_estudiantsMatriculats[m_nEstudiants][1] = niu;
}

bool Assignatura::afegeixNota(string niu, float nota)
{

    bool correcte = false;
    int num = 0;
    num = cercaEstudiant(m_estudiantsMatriculats, m_nEstudiants, niu);
    if (num == -1)
        correcte = false;
    else
    {
        correcte = true;
        m_estudiantsMatriculats[num].afegeixNota(nota);
    }
    return correcte;
}

float Assignatura::calculaNotaMitjana(string niu)
{
    float mitjana;
    int pos = cercaEstudiant(m_estudiantsMatriculats, m_nEstudiants, niu);
    if (pos != -1)
        mitjana = m_estudiantsMatriculats[pos].calculaNotaMitjana();
    else
        mitjana = -1.0;
    return mitjana;
}
