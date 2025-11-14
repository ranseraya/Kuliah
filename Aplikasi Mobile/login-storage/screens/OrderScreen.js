import { View, Text, StyleSheet, FlatList, TouchableOpacity } from 'react-native';
import { Ionicons } from '@expo/vector-icons';

const dummyOrders = [
  {
    id: '1',
    service: 'URide',
    date: '12 Nov 2025, 14:30',
    total: 'Rp 25.000',
    status: 'Selesai',
  },
  {
    id: '2',
    service: 'UFood',
    date: '12 Nov 2025, 12:15',
    total: 'Rp 85.000',
    status: 'Selesai',
  },
  {
    id: '3',
    service: 'USend',
    date: '11 Nov 2025, 09:05',
    total: 'Rp 18.000',
    status: 'Dibatalkan',
  },
  {
    id: '4',
    service: 'UCar',
    date: '10 Nov 2025, 18:00',
    total: 'Rp 65.000',
    status: 'Selesai',
  },
];

const getServiceIcon = (service) => {
  switch (service) {
    case 'URide':
      return 'bicycle-outline';
    case 'UCar':
      return 'car-sport-outline';
    case 'UFood':
      return 'fast-food-outline';
    case 'USend':
      return 'paper-plane-outline';
    default:
      return 'ellipse-outline';
  }
};

export default function OrderScreen({ navigation }) {

  const renderOrderItem = ({ item }) => (
    <TouchableOpacity style={styles.card}>
      <View style={[styles.iconContainer, { backgroundColor: item.status === 'Selesai' ? '#e6f5f0' : '#fceded' }]}>
        <Ionicons 
          name={getServiceIcon(item.service)} 
          size={24} 
          color={item.status === 'Selesai' ? '#009966' : '#d9534f'} 
        />
      </View>

      <View style={styles.infoContainer}>
        <Text style={styles.serviceName}>{item.service}</Text>
        <Text style={styles.date}>{item.date}</Text>
      </View>
      
      <View style={styles.statusContainer}>
        <Text style={styles.total}>{item.total}</Text>
        <Text style={[
          styles.status, 
          { color: item.status === 'Selesai' ? '#009966' : '#d9534f' }
        ]}>
          {item.status}
        </Text>
      </View>
    </TouchableOpacity>
  );

  return (
    <View style={styles.container}>
      <Text style={styles.headerTitle}>Riwayat Pesanan</Text>
      <FlatList
        data={dummyOrders}
        renderItem={renderOrderItem}
        keyExtractor={(item) => item.id}
        contentContainerStyle={{ paddingBottom: 20 }}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#f9f9f9',
  },
  headerTitle: {
    fontSize: 24,
    fontWeight: 'bold',
    paddingHorizontal: 20,
    paddingTop: 20,
    paddingBottom: 10,
    backgroundColor: '#fff',
  },
  card: {
    backgroundColor: '#fff',
    borderRadius: 12,
    padding: 15,
    marginHorizontal: 16,
    marginVertical: 8,
    flexDirection: 'row',
    alignItems: 'center',
    shadowColor: '#000',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.1,
    shadowRadius: 4,
    elevation: 3,
  },
  iconContainer: {
    padding: 12,
    borderRadius: 30,
    marginRight: 15,
  },
  infoContainer: {
    flex: 1,
  },
  serviceName: {
    fontSize: 16,
    fontWeight: 'bold',
    color: '#333',
  },
  date: {
    fontSize: 13,
    color: 'gray',
    marginTop: 2,
  },
  statusContainer: {
    alignItems: 'flex-end',
  },
  total: {
    fontSize: 16,
    fontWeight: '600',
    color: '#333',
  },
  status: {
    fontSize: 13,
    fontWeight: 'bold',
    marginTop: 2,
  },
});