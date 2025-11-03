import React from 'react';
import { View, Text, StyleSheet, TouchableOpacity, ScrollView } from 'react-native';
import { SafeAreaView } from 'react-native-safe-area-context'; 

const projects = [
  {
    title: 'Aplikasi Kalkulator Sederhana',
    description: 'Aplikasi untuk melakukan operasi aritmatika dasar yang dibangun dengan Java.',
  },
  {
    title: 'Website Portofolio HTML & CSS',
    description: 'Sebuah website statis untuk menampilkan profil diri dan proyek.',
  },
  {
    title: 'Aplikasi To-Do List',
    description: 'Aplikasi sederhana untuk mencatat daftar tugas harian menggunakan React Native.',
  },
];

const Projects = ({ navigation }) => {
  return (
    <SafeAreaView style={styles.container}>
      <ScrollView>
        <Text style={styles.headerTitle}>Proyek Saya</Text>
        {projects.map((project, index) => (
          <View key={index} style={styles.projectCard}>
            <Text style={styles.projectTitle}>{project.title}</Text>
            <Text style={styles.projectDescription}>{project.description}</Text>
          </View>
        ))}
      </ScrollView>
      <View style={styles.buttonContainer}>
        <TouchableOpacity style={styles.button} onPress={() => navigation.goBack()}>
          <Text style={styles.buttonText}>Kembali</Text>
        </TouchableOpacity>
      </View>
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#f5f6fa',
    padding: 20,
  },
  headerTitle: {
    fontSize: 28,
    fontWeight: 'bold',
    color: '#2c3e50',
    marginBottom: 20,
    textAlign: 'center',
  },
  projectCard: {
    backgroundColor: 'white',
    borderRadius: 10,
    padding: 20,
    marginBottom: 15,
    elevation: 3,
  },
  projectTitle: {
    fontSize: 18,
    fontWeight: 'bold',
    color: '#34495e',
  },
  projectDescription: {
    fontSize: 14,
    color: '#7f8c8d',
    marginTop: 5,
  },
  buttonContainer: {
    marginTop: 20,
  },
  button: {
    backgroundColor: '#e74c3c',
    padding: 15,
    borderRadius: 10,
    alignItems: 'center',
  },
  buttonText: {
    color: 'white',
    fontSize: 16,
    fontWeight: 'bold',
  },
});

export default Projects;