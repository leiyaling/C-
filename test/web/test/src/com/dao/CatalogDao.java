package com.dao;

import java.util.List;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;
import org.springframework.stereotype.Repository;
import com.bean.Catalog;

@Repository("catalogDao")
public interface CatalogDao {

	@Select("select * from catalog")
	public List<Catalog> selectCatalog();
	
	@Insert("insert into catalog(catalogname) values(#{catalogname})")
	public int addCatalog(Catalog catalog);
	
	@Update("update catalog set catalogname=#{catalogname} where catalogid=#{catalogid}")
	public int updateCatalog(Catalog catalog);
	
	@Select("select * from catalog where catalogid=#{catalogid}")
	public Catalog selectCatalogByCatalogId(int catalogid);
	
	@Delete("delete from catalog where catalogid=#{catalogid}")
	public int deleteCatalog(int catalogid);
}
