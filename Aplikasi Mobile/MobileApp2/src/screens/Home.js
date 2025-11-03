import React from 'react';
import { View, Text, StyleSheet, TouchableOpacity } from 'react-native';
import { SafeAreaView } from 'react-native-safe-area-context'; 

const Home = ({ navigation }) => {
  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.header}>
        <Text style={styles.title}>Selamat Datang!</Text>
        <Text style={styles.subtitle}>
          Ini adalah aplikasi portofolio sederhana saya yang dibuat dengan React Native.
        </Text>
      </View>
      <View style={styles.menuContainer}>
        <TouchableOpacity
          style={styles.button}
          onPress={() => navigation.navigate('AboutMe')}>
          <Text style={styles.buttonText}>👨‍💻 About Me</Text>
        </TouchableOpacity>
        <TouchableOpacity
          style={styles.button}
          onPress={() => navigation.navigate('Projects')}>
          <Text style={styles.buttonText}>📁 Projects</Text>
        </TouchableOpacity>
        <TouchableOpacity
          style={styles.button}
          onPress={() => navigation.navigate('ContactMe')}>
          <Text style={styles.buttonText}>📞 Contact Me</Text>
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
  header: {
    marginBottom: 40,
    alignItems: 'center',
  },
  title: {
    fontSize: 28,
    fontWeight: 'bold',
    color: '#2c3e50',
    marginTop: 20,
  },
  subtitle: {
    fontSize: 16,
    color: '#7f8c8d',
    textAlign: 'center',
    marginTop: 10,
  },
  menuContainer: {
    width: '100%',
  },
  button: {
    backgroundColor: '#3498db',
    padding: 20,
    borderRadius: 10,
    marginBottom: 20,
    alignItems: 'center',
    elevation: 3,
  },
  buttonText: {
    color: 'white',
    fontSize: 18,
    fontWeight: 'bold',
  },
});

export default Home;