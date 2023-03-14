package com.service;

import java.util.List;
import javax.annotation.Resource;
import org.springframework.stereotype.Service;
import com.bean.Catalog;
import com.dao.CatalogDao;

@Service("catalogService")
public class CatalogService {

	@Resource(name="catalogDao")
	CatalogDao catalogDao;
	
	public List<Catalog> selectCatalog(){
		return catalogDao.selectCatalog();
	}
	
	public int addCatalog(Catalog catalog){
		return catalogDao.addCatalog(catalog);
	}
	
	public int updateCatalog(Catalog catalog){
		return catalogDao.updateCatalog(catalog);
	}
	
	public Catalog selectCatalogByCatalogId(int catalogid){
		return catalogDao.selectCatalogByCatalogId(catalogid);
	}
	
	public int deleteCatalog(int catalogid){
		return catalogDao.deleteCatalog(catalogid);
	}
}
