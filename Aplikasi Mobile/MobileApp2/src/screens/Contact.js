import React from 'react';
import { View, Text, StyleSheet, TouchableOpacity } from 'react-native';
import { SafeAreaView } from 'react-native-safe-area-context';
 
const Contact = ({ navigation }) => {
  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.content}>
        <Text style={styles.headerTitle}>Contact Me</Text>
        <View style={styles.contactCard}>
          <Text style={styles.contactLabel}>📧 Email</Text>
          <Text style={styles.contactInfo}>23081010071@student.upnjatim.ac.id</Text>
        </View>
        <View style={styles.contactCard}>
          <Text style={styles.contactLabel}>🔗 LinkedIn</Text>
          <Text style={styles.contactInfo}>linkedin.com/in/ranseraya</Text>
        </View>
        <View style={styles.contactCard}>
          <Text style={styles.contactLabel}>👨‍💻 GitHub</Text>
          <Text style={styles.contactInfo}>github.com/ranseraya</Text>
        </View>
      </View>
      <TouchableOpacity style={styles.button} onPress={() => navigation.goBack()}>
        <Text style={styles.buttonText}>Back</Text>
      </TouchableOpacity>
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#f5f6fa',
    padding: 20,
    justifyContent: 'space-between',
  },
  content: {
    flex: 1,
  },
  headerTitle: {
    fontSize: 28,
    fontWeight: 'bold',
    color: '#2c3e50',
    marginBottom: 30,
    textAlign: 'center',
  },
  contactCard: {
    backgroundColor: 'white',
    borderRadius: 10,
    padding: 20,
    marginBottom: 15,
    elevation: 3,
  },
  contactLabel: {
    fontSize: 14,
    color: '#7f8c8d',
  },
  contactInfo: {
    fontSize: 18,
    color: '#2980b9',
    marginTop: 5,
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

export default Contact;