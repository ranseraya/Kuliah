<?php
error_reporting(0);

$host = "localhost";
$user = "root";
$pass = "" ;
$db  = "api_rn";

$koneksi = mysqli_connect($host, $user, $pass, $db);

$op = $_GET['op'];
switch($op){
    case '':normal();break;
    default:normal();break;
    case 'create':create();break;
    case 'detail':detail();break;
    case 'update':update();break;
    case 'delete':delete();break;
}

function normal(){
    global $koneksi;
    $sql1 = "select * from mahasiswa order by id desc";
    $q1 = mysqli_query($koneksi, $sql1);
    while($r1 = mysqli_fetch_array($q1)){
        $hasil[] = array(
            'id' => $r1['id'],
            'npm' => $r1['npm'],
            'nama' => $r1['nama'],
            'program_studi' => $r1['program_studi'],
            'tanggal_input' => $r1['tanggal_input']
        );
    }
    $data['data']['result'] = $hasil;
    echo json_encode($data);
}

function create(){
    global $koneksi;
    $npm = $_POST['npm'];
    $nama = $_POST['nama'];
    $program_studi = $_POST['program_studi'];
    $hasil = "Gagal dimasukkan data";
    if($nama and $npm and $program_studi){
        $sql1 = "insert into mahasiswa (npm, nama, program_studi) values
        ('$npm', '$nama', '$program_studi')";
        $q1 = mysqli_query($koneksi, $sql1);
        if($q1){
            $hasil = "Berhasil menambahkan data";
        }
    }
    $data['data']['result'] = $hasil;
    echo json_encode($data);
}

function detail(){
    global $koneksi;
    $id = $_GET['id'];
    $sql1 = "select * from mahasiswa where id =  '$id'";
    $q1 = mysqli_query($koneksi, $sql1);
    while($r1 = mysqli_fetch_array($q1)){
        $hasil[] = array(
            'id' => $r1['id'],
            'npm' => $r1['npm'],
            'nama' => $r1['nama'],
            'program_studi' => $r1['program_studi'],
            'tanggal_input' => $r1['tanggal_input']
        );
    }
    $data['data']['result'] = $hasil;
    echo json_encode($data);
}

function update(){
    global $koneksi;
    $id = $_GET['id'];
    $npm = $_POST['npm'];
    $nama = $_POST['nama'];
    $program_studi = $_POST['program_studi'];
    $tanggal_input = $_POST['tanggal_input'];
    if($npm){
        $set[] = "npm='$npm";
    }
    if($nama){
        $set[] = "nama='$nama";
    }
    if($program_studi){
        $set[] = "program_studi='$program_studi";
    }
    $hasil = "Gagal melakukan update data";
    if($nama or $alamat or $npm or $program_studi){
        $sql1 = "update mahasiswa set ".implode(",",$set) .",tanggal_input=now() where  id = '$id'";
        $q1 = mysqli_query($koneksi, $sql1);
        if($q1){
            $hasil = "Data berhasil diupdate";
        }
    }
    $data['data']['result'] = $hasil;
    echo json_encode($data);
}

function delete(){
    global $koneksi;
    $id = $_GET['id'];
    $sql1 = "delete from mahasiswa where id =  '$id'";
    $q1 = mysqli_query($koneksi, $sql1);
    if($q1){
        $hasil = "Berhasil menghapus data";
    } else {
        $hasil = "Gagal menghapus data";
    }
    $data['data']['result'] = $hasil;
    echo json_encode($data);
}
?>