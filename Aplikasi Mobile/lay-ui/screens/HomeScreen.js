import { View, Text, StyleSheet, FlatList, TouchableOpacity } from 'react-native';

const services = [
    { id: 1, name: "URide"},
    { id: 2, name: "UCar"},
    { id: 3, name: "UFoof"},
    { id: 4, name: "USend"},
    { id: 5, name: "UMart"},
    { id: 6, name: "UPulsa"},
];

export default function HomeeScreen(){
    return (
        <View style={styles.container}>
            <Text style={styles.header}>Selamat Datang di Ujek</Text>
            <FlatList
            data={services}
            numColumns={3}
            keyExtractor={item => item.id.toString()}
            renderItem={({ item }) => (
                <TouchableOpacity style={styles.card}>
                    <Text style={styles.cardText}>{item.name}</Text>
                </TouchableOpacity>
            )}
            />
        </View>
    );
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        padding: 20, 
        backgroundColor: '#fff',
    },
    header: {
        fontSize: 20,
        fontWeight: 'bold',
        marginBottom: 20,
        color: '#009966',
    },
    card: {
        flex: 1,
        margin: 10,
        padding: 20,
        backgroundColor: '#f2f2f2',
        borderRadius: 10,
        alignItems: 'center',
    },
    cardText: {
        fontWeight: '600',
        fontSize: 13,
    },
});