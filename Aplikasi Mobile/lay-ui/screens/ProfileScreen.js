import { View, Text, StyleSheet, TouchableOpacity, ScrollView, Alert } from 'react-native';
import { Ionicons } from '@expo/vector-icons';

const ProfileMenuItem = ({ icon, name, onPress }) => (
  <TouchableOpacity style={styles.menuItem} onPress={onPress}>
    <View style={styles.menuLeft}>
      <Ionicons name={icon} size={22} color="#009966" />
      <Text style={styles.menuItemText}>{name}</Text>
    </View>
    <Ionicons name="chevron-forward-outline" size={22} color="gray" />
  </TouchableOpacity>
);

export default function ProfileScreen({ navigation, user }) {

  const handleLogout = () => {
    Alert.alert(
      "Logout",
      "Apakah Anda yakin ingin keluar?",
      [
        {
          text: "Batal",
          style: "cancel"
        },
        { 
          text: "Ya, Keluar", 
          onPress: () => {
            navigation.reset({
              index: 0,
              routes: [{ name: 'Login' }],
            });
          },
          style: "destructive"
        }
      ]
    );
  };

  return (
    <ScrollView style={styles.container}>
      <View style={styles.profileHeader}>
        <Ionicons name="person-circle-outline" size={100} color="#ccc" />
        <Text style={styles.userName}>
          {user ? user.name : 'Ayala Rahanda'}
        </Text>
        <Text style={styles.userEmail}>
          {user ? user.email : '23081010071@student.upnjatim.ac.id'}
        </Text>
        <Text style={styles.userEmail}>
          NPM: {user ? user.npm: '23081010071'}
        </Text>
      </View>

      <View style={styles.menuContainer}>
        <ProfileMenuItem 
          icon="person-outline" 
          name="Edit Profil" 
          onPress={() => Alert.alert("Fitur", "Halaman Edit Profil belum tersedia.")} 
        />
        <ProfileMenuItem 
          icon="settings-outline" 
          name="Pengaturan" 
          onPress={() => Alert.alert("Fitur", "Halaman Pengaturan belum tersedia.")} 
        />
        <ProfileMenuItem 
          icon="help-circle-outline" 
          name="Pusat Bantuan" 
          onPress={() => Alert.alert("Fitur", "Halaman Bantuan belum tersedia.")} 
        />
        <ProfileMenuItem 
          icon="information-circle-outline" 
          name="Tentang Kami" 
          onPress={() => Alert.alert("Fitur", "Halaman Tentang Kami belum tersedia.")} 
        />
      </View>

      <TouchableOpacity style={styles.logoutButton} onPress={handleLogout}>
        <Text style={styles.logoutButtonText}>Logout</Text>
      </TouchableOpacity>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#f2f2f2',
  },
  profileHeader: {
    backgroundColor: '#fff',
    paddingVertical: 30,
    alignItems: 'center',
    borderBottomLeftRadius: 20,
    borderBottomRightRadius: 20,
    elevation: 3,
    shadowColor: '#000',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.1,
    shadowRadius: 4,
  },
  userName: {
    fontSize: 22,
    fontWeight: 'bold',
    color: '#333',
    marginTop: 10,
  },
  userEmail: {
    fontSize: 16,
    color: 'gray',
    marginTop: 4,
  },
  userNPM: {
    fontSize: 16,
    color: 'blue',
    marginTop: 4,
  },
  menuContainer: {
    marginTop: 20,
    marginHorizontal: 10,
    backgroundColor: '#fff',
    borderRadius: 12,
    overflow: 'hidden',
  },
  menuItem: {
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'space-between',
    paddingVertical: 15,
    paddingHorizontal: 20,
    borderBottomWidth: 1,
    borderBottomColor: '#f5f5f5',
  },
  menuLeft: {
    flexDirection: 'row',
    alignItems: 'center',
  },
  menuItemText: {
    fontSize: 16,
    marginLeft: 15,
    color: '#444',
  },
  logoutButton: {
    marginTop: 30,
    marginHorizontal: 10,
    backgroundColor: '#fff',
    borderRadius: 12,
    paddingVertical: 15,
    alignItems: 'center',
    marginBottom: 40,
  },
  logoutButtonText: {
    color: '#d9534f',
    fontSize: 16,
    fontWeight: 'bold',
  },
});